#include <iostream>
#include <atomic>
#include <thread>
#include <vector>
#include <string>
#include <chrono>

class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& msg) {
        // Atomically reserve a slot
        size_t idx = writeIndex.fetch_add(1, std::memory_order_relaxed) % BUFFER_SIZE;
        buffer[idx] = msg;
    }

    void flush() {
        size_t idx = readIndex.load(std::memory_order_relaxed);
        while (idx < writeIndex.load(std::memory_order_relaxed)) {
            std::cout << "[LOG] " << buffer[idx % BUFFER_SIZE] << "\n";
            ++idx;
        }
        readIndex.store(idx, std::memory_order_relaxed);
    }

private:
    Logger() {
        std::cout << "Logger initialized\n";
    }

    static constexpr size_t BUFFER_SIZE = 1024;
    std::string buffer[BUFFER_SIZE];

    std::atomic<size_t> writeIndex{0};
    std::atomic<size_t> readIndex{0};
};

// Background thread that flushes logs periodically
void flusher() {
    while (true) {
        Logger::getInstance().flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// Worker threads that generate logs
void worker(int id) {
    for (int i = 0; i < 5; ++i) {
        Logger::getInstance().log("Worker " + std::to_string(id) + " message " + std::to_string(i));
    }
}

int main() {
    // Start background flusher
    std::thread flushThread(flusher);

    // Start workers
    constexpr int NUM_THREADS = 4;
    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(worker, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    // Let flusher run a bit
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // In real systems, you'd signal flushThread to stop gracefully
    flushThread.detach();
}
