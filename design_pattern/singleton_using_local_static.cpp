#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

using namespace std;

/*
    emplace_back constructs an element directly in place at the end of the container, 
    instead of creating a temporary object and then copying or moving it in.

    push_back: Requires you to already have an object, then copies or moves it into the container.
    emplace_back: Constructs the object inside the container using the arguments you pass. This avoids an extra copy/move.
*/

// ✅ Meyers' Singleton with real-time safety
class Logger{
    public:
        static Logger& getInstance(){
            /*
                Function local static (like in Meyers’ Singleton)
                Initialized the first time the function is called. Means only one thread initilize other thread use same instance by created first thread.
                C++11 and later: initialization is guaranteed thread‑safe.
                Lifetime: until program termination.
                Not destroyed when the function returns — it persists globally.
                A normal local variable is created each time the function runs.
                A function‑local static variable is created only once, shared across all calls and threads
                Class member static : Initialized once, usually defined outside the class.
                In C++, any static variable (whether global, class‑level, or function‑local) is initialized only once during the lifetime of the program. 
            */
            static Logger instance; // Thread-safe, lazy init. one instance, shared
            //static Logger& instance = *new Logger(); // allocated once, never freed
            //cout<<"in getInstance "<<instance<<"\n";
            return instance;
        }
        void log(const std::string& msg){
            cout<<"[LOG] " << msg <<"\n";
        }
        void logAddress() {
            std::cout << "Thread " << this_thread::get_id()
                      << " instance address: " << this << "\n";
        }
    private:
        Logger(){
            std::cout << "Logger initialized\n";
        }
        // prevent destructor order issue
        //~Logger() = default;  // Not needed
        ~Logger() { std::cout << "Logger destroyed\n"; }

        // prevent copy/move
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        Logger(Logger&&) = delete;
        Logger& operator=(Logger&&) = delete;
};

// ✅ Example usage in concurrent system
void worker(int id) {
    Logger::getInstance().log("Worker " + std::to_string(id) + " started");
    Logger::getInstance().logAddress();
}

int main() {
    constexpr int NUM_THREADS = 5;
    vector<thread> threads;
    
    for(int i = 0; i < NUM_THREADS; ++i){
        threads.emplace_back(worker, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
