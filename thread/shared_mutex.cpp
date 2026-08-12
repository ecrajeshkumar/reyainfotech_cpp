#include <iostream>
#include <shared_mutex>
#include <thread>
#include <vector>

std::shared_mutex sm;
int data = 0;

void reader(int id) {
    std::shared_lock<std::shared_mutex> lock(sm);
    std::cout << "Reader " << id << " sees data = " << data << "\n";
}

void writer(int id) {
    std::unique_lock<std::shared_mutex> lock(sm);
    data += 10;
    std::cout << "Writer " << id << " updated data = " << data << "\n";
}

int main() {
    std::vector<std::thread> threads;

    // Start readers
    for (int i = 0; i < 3; i++) threads.emplace_back(reader, i);

    // Start writers
    for (int i = 0; i < 2; i++) threads.emplace_back(writer, i);

    for (auto &t : threads) t.join();
}
