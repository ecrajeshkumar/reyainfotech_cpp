#include <iostream>
#include <thread>
#include <shared_mutex>
#include <chrono>

using namespace std;

std::shared_timed_mutex rw_mutex;
int shared_data = 0;

// Writer function (exclusive lock)
void writer() {
    std::unique_lock<std::shared_timed_mutex> lock(rw_mutex);
    cout << "Writer started, holding lock..." << endl;
    std::this_thread::sleep_for(std::chrono::seconds(3)); // simulate long write
    ++shared_data;
    cout << "Writer updated shared_data to " << shared_data << endl;
}

// Reader function (timed shared lock)
void reader(int id) {
    std::shared_lock<std::shared_timed_mutex> lock(rw_mutex, std::defer_lock);

    if (lock.try_lock_for(std::chrono::seconds(1))) {
        cout << "Reader " << id << " acquired lock, sees shared_data = "
             << shared_data << endl;
    } else {
        cout << "Reader " << id << " timed out waiting for lock." << endl;
    }
}

int main() {
    thread w(writer);
    thread r1(reader, 1);
    thread r2(reader, 2);

    w.join();
    r1.join();
    r2.join();

    return 0;
}
