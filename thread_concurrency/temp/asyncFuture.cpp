/*
    std::async => Launches the function Operation(10) asynchronously in a new thread (because we specified std::launch::async).
                  Returns a std::future<int> that will eventually hold the result of Operation.
                  std::async creates a shared state internally. The return value of Operation is stored in that shared state.
                  The shared state is the “bridge” between the producer (the async task/thread) and the consumer (your main thread).
                  The async thread writes the result into the shared state.
                  The future reads the result from the shared state when you call get().
                  Once get() is called, the shared state is consumed, and result.valid() becomes false.
    std::future<int> result => A future object that represents the eventual return value of Operation(thread).
                It’s an object that represents a result which will be available later.
                We can later call result.get() to retrieve the value (blocking until it’s ready).
                That result comes from a shared state created by std::async, std::promise, or std::packaged_task.
                The std::future<int> object (result) is your handle to that shared state.
    result.valid() => Checks if the future is associated with a shared state. 
                Returns true if the future is valid, false otherwise.
                Important: once you call result.get(), the future becomes invalid (because the shared state is consumed).
                valid() only tells you if the future has a result pending. It does not tell us if the task has finished yet.



*/

#include <future>
#include <iostream>

int operationSum(int num){
    using namespace std::chrono_literals; 
    int sum{};
    for(int i = 0; i < num; ++i){
        sum+=i;
    }
    std::this_thread::sleep_for(1000ms);    // 1 seconds
    //std::this_thread::sleep_for(std::chrono::seconds(1)); // 1 seconds
    return sum;
}


int main(){
    std::future<int> result = std::async(std::launch::async, operationSum, 100);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    if(result.valid()){  //
        auto status = result.wait_until(std::chrono::system_clock::now() + std::chrono::seconds(1));
        //auto status = result.wait_for(std::chrono::milliseconds(1));
        switch(status){
            case std::future_status::deferred:
                std::cout << "Task is synchronous \n";
                break;
            case std::future_status::ready:
                std::cout<<"Result is ready\n";
                break;
            case std::future_status::timeout:
                std::cout<<"Task is still running \n";
                break;
        }
    }
    else{
        std::cout << "Shared state not created !!!\n";
    }
    auto sum = result.get();
    std::cout<<"Sum = "<<sum<<"\n";
    return 0;
}