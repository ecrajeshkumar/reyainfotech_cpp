#include <iostream>
#include <thread>
#include <vector>
#include <functional>
#include <chrono>

// Worker function that takes an id and a callback
void workerTask(int id, std::function<void(int, int)> callback) {
    std::cout << "Worker " << id << " started...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500 + id * 200)); // simulate work
    int result = id * id; // pretend computation
    std::cout << "Worker " << id << " finished!\n";
    callback(id, result); // report result back
}

int main() {
    // Callback function: receives worker id and result
    auto reportResult = [](int id, int result) {
        std::cout << "Callback: Worker " << id << " produced result = " << result << "\n";
    };

    // Launch multiple worker threads
    std::vector<std::thread> workers;
    for (int i = 1; i <= 4; i++) {
        workers.emplace_back(workerTask, i, reportResult);
    }

    // Join all threads
    for (auto& t : workers) {
        t.join();
    }

    std::cout << "All workers finished.\n";
    return 0;
}
