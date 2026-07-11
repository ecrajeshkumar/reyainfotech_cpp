#include <iostream>
#include <functional>
#include <thread>
#include <chrono>

// A function that accepts a callback
void asyncTask(std::function<void(int)> callback) {
    std::cout << "Task started...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // simulate work
    int result = 42; // pretend we computed something
    std::cout << "Task finished!\n";
    callback(result); // invoke the callback
}

int main() {
    // Pass a lambda as callback
    asyncTask([](int value) {
        std::cout << "Callback received result: " << value << "\n";
    });

    // Pass a normal function as callback
    auto printResult = [](int value) {
        std::cout << "Another callback got: " << value << "\n";
    };
    asyncTask(printResult);

    return 0;
}
