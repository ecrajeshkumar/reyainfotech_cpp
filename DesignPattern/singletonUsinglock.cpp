#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

class Singleton {
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {                 // First check (no lock)
            std::lock_guard<std::mutex> lock(initMutex);
            if (instance == nullptr) {             // Second check (with lock)
                instance = new Singleton();
            }
        }
        return instance;
    }

    void logAddress(int id) {
        std::cout << "Thread " << id 
                  << " Singleton instance address: " 
                  << static_cast<const void*>(this) << "\n";
    }

private:
    Singleton() {
        std::cout << "Singleton initialized\n";
    }

    // Prevent copy/move
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance;
    static std::mutex initMutex;
};

// Static member definitions
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::initMutex;

// Example usage
void worker(int id) {
    Singleton::getInstance()->logAddress(id);
}

int main() {
    constexpr int NUM_THREADS = 5;
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(worker, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
