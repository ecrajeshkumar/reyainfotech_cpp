#include <iostream>
#include <thread>
#include <atomic>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <unordered_map>
#include <variant>

// -----------------------------
// Base Event Interface
// -----------------------------
class BaseEvent{
    public:
        BaseEvent(){}
        BaseEvent(int priority){
            this->priority = priority;
        }
        virtual ~BaseEvent() = default;
        int getPriority() const {
            return priority;
        }
    protected:
        int priority; // Higher = more urgent
};

// Example event types
class CANMessage : public BaseEvent{
    public:
        CANMessage(){}
        CANMessage(int priority, int id, const std::string& payload):BaseEvent(priority){
            this->id = id;
            this->payload = payload;
        }
        int getId() const {
            return id;
        }
        std::string getPayload() const {
            return payload;
        }
    private:
        int id;
        std::string payload;
};

class SensorData : public BaseEvent{
    public:
        SensorData(){}
        SensorData(int priority, double value):BaseEvent(priority){
            this->value = value;
        }
        double getValue() const {
            return value;
        }
    private:
        double value;
};

class MediaCommand : public BaseEvent{
    public:
        MediaCommand(){}
        MediaCommand(int priority, const std::string& command):BaseEvent(priority){
            this->command = command;
        }
        std::string getCommand() const {
            return command;
        }
    private:
        std::string command;
};

// -----------------------------
// Comparator for Priority Queue
// -----------------------------
class EventCompare{
    public:
        bool operator()(const std::shared_ptr<BaseEvent>& a, const std::shared_ptr<BaseEvent>& b) const {
            return a->getPriority() < b->getPriority(); // max-heap
        }
};

// -----------------------------
// Event Dispatcher
// -----------------------------
class EventDispatcher {
public:
    EventDispatcher() : running(true) {
        worker = std::thread(&EventDispatcher::dispatchLoop, this);
    }

    ~EventDispatcher() {
        shutdown();
    }

    template <typename Event>
    void registerHandler(std::function<void(const Event&)> handler) {
        std::lock_guard<std::mutex> lock(handlerMutex);
        auto typeId = typeid(Event).hash_code();
        handlers[typeId] = [handler](const BaseEvent& e) {
            handler(static_cast<const Event&>(e));
        };
    }

    void pushEvent(std::shared_ptr<BaseEvent> event) {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            eventQueue.push(event);
        }
        cv.notify_one();
    }

    void shutdown() {
        {
            std::lock_guard<std::mutex> lock(queueMutex);
            running = false;
        }
        cv.notify_all();
        if (worker.joinable()) worker.join();
    }

private:
    std::priority_queue<
        std::shared_ptr<BaseEvent>,
        std::vector<std::shared_ptr<BaseEvent>>,
        EventCompare
    > eventQueue;

    std::unordered_map<size_t, std::function<void(const BaseEvent&)>> handlers;

    std::mutex queueMutex;
    std::mutex handlerMutex;
    std::condition_variable cv;
    std::thread worker;
    bool running;

    void dispatchLoop() {
        while (true) {
            std::unique_lock<std::mutex> lock(queueMutex);
            cv.wait(lock, [this] { return !eventQueue.empty() || !running; });

            if (!running && eventQueue.empty()) break;

            auto event = eventQueue.top();
            eventQueue.pop();
            lock.unlock();

            auto typeId = typeid(*event).hash_code();
            std::lock_guard<std::mutex> hlock(handlerMutex);
            if (handlers.find(typeId) != handlers.end()) {
                handlers[typeId](*event);
            }
        }
    }
};

// -----------------------------
// Example Usage
// -----------------------------
int main() {
    EventDispatcher dispatcher;

    dispatcher.registerHandler<CANMessage>([](const CANMessage& msg) {
        std::cout << "[CAN] ID: " << msg.getId() << " Payload: " << msg.getPayload() << "\n";
    });

    dispatcher.registerHandler<SensorData>([](const SensorData& data) {
        std::cout << "[Sensor] Value: " << data.getValue() << "\n";
    });

    dispatcher.registerHandler<MediaCommand>([](const MediaCommand& cmd) {
        std::cout << "[Media] Command: " << cmd.getCommand() << "\n";
    });

    // Push events with different priorities
    dispatcher.pushEvent(std::make_shared<CANMessage>(CANMessage(5, 101, "EngineStart")));
    dispatcher.pushEvent(std::make_shared<SensorData>(SensorData(3, 36.7)));
    dispatcher.pushEvent(std::make_shared<MediaCommand>(MediaCommand(10, "PlaySong")));

    std::this_thread::sleep_for(std::chrono::seconds(1));
    dispatcher.shutdown();

    return 0;
}
