/*

    std::shared_timed_mutex ort shared_mutex
    Allows multiple readers to hold the lock simultaneously.
    Only one writer can hold it exclusively, blocking readers.

    std::shared_lock:
    Acquires a shared (read) lock.
    Multiple threads can read concurrently.
    Writers must wait until all readers release the lock.

    std::unique_lock:
    Acquires an exclusive (write) lock.
    Blocks all readers and other writers until released.

    we can absolutely pass a std::shared_mutex (or std::shared_timed_mutex) into a std::unique_lock.

*/



#include <iostream>
#include <thread>
#include <shared_mutex>   // for std::shared_timed_mutex and std::shared_lock
#include <vector>

using namespace std;

shared_timed_mutex rw_mutex; // reader-writer mutex;
int shared_data = 0;

void reader(int id){
    shared_lock<shared_timed_mutex> lock(rw_mutex);
    cout<<"Reader_"<<id<<" sees shared_data = "<<shared_data;
}

void writer(int id){
    unique_lock<shared_timed_mutex> lock(rw_mutex); // exclusive (write) lock
    ++shared_data;
    cout << "Writer_" << id << " updated shared_data to " << shared_data << endl;
}

int main(){

    vector<thread> threads;

    // start three reader threads
    for(int i = 1; i <= 3; ++i){
        threads.emplace_back(reader, i);
    }
    // start one writer thread
    threads.emplace_back(writer, 10);

    // More readers after writer
    for(int i = 4; i <= 5; ++i){
        threads.emplace_back(reader, i);
    }

    // join all thread
    for(auto& th : threads)
        th.join();
    return 0;
}