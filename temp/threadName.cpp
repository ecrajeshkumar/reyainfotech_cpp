#include <iostream>
#include <thread>
#include <pthread.h> // for pthread_setname_np

void Process() {
    char name[16];
    pthread_getname_np(pthread_self(), name, sizeof(name));
    std::cout << "[Process] Thread name: " << name << std::endl;
    
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << i << ' ';
    }
}

int main() {
    std::thread t1(Process);

    // Linux-specific: set thread name
    pthread_setname_np(t1.native_handle(), "MyThread");
    
    char name[16];
    pthread_getname_np(t1.native_handle(), name, sizeof(name));
    std::cout << "[Main] Thread name: " << name << std::endl;
    
    auto id = t1.get_id();
    std::cout << "\nt1.get_id() = " << id << std::endl;

    int cores = std::thread::hardware_concurrency();
    std::cout << "Cores: " << cores << std::endl;

    t1.join();
    return 0;
}
