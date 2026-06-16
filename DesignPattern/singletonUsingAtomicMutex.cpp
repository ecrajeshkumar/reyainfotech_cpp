#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>

class Singleton {
public:
    static Singleton* getInstance() {
        // First check (no lock) for performance
        Singleton* tmp = instance.load(std::memory_order_acquire);
        if (tmp == nullptr) {
            std::lock_guard<std::mutex> lock(initMutex);
            tmp = instance.load(std::memory_order_relaxed);
            if (tmp == nullptr) {
                tmp = new Singleton();
                instance.store(tmp, std::memory_order_release);
            }
        }
        return tmp;
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
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static std::atomic<Singleton*> instance;
    static std::mutex initMutex;
};

// Static member definitions
std::atomic<Singleton*> Singleton::instance{nullptr};
std::mutex Singleton::initMutex;

// Example usage
void worker(int id) {
    Singleton::getInstance()->logAddress(id);
}

int main() {
    constexpr int NUM_THREADS = 8;
    std::vector<std::thread> threads;

    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(worker, i);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
