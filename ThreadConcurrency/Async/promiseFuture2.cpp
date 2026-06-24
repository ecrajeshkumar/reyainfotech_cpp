#include <future>
#include <iostream>


int main(){
    // 1. Create a promise
    std::promise<int> prom;
    // 2. Get the future from the promise (shared state created here)
    std::future<int> result = prom.get_future();

    // 3. Launch a thread that fulfills the promise
    std::thread worker([&prom](){
        std::cout<<"Data is setting throgh worker thread\n";
       //std::this_thread::sleep_for(std::chrono::seconds(2));
        prom.set_value(100); // producer sets the result
    });
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout<<"Retrive data is "<<result.get()<<"\n";
    worker.join();
    return 0;
}