#include <future>
#include <iostream>


int operation(std::future<int> f){
    using namespace std::chrono_literals;
    int sum{};
    std::this_thread::sleep_for(300ms);
    try{
        auto count = f.get();
        for(int i = 0; i < count; ++i){
            sum += i;
        }
    }catch(std::exception &ex){
        std::cout<<"[Task] Exception:"<<ex.what() <<std::endl;
    }
    return sum;
}


int main(){
    using namespace std::chrono_literals ;
    std::promise<int> prom;
    auto fut = prom.get_future();
    //std::future<int> result = std::async(std::launch::async, operation, std::ref(fut));
    std::future<int> result = std::async(std::launch::async, operation, std::move(fut));
    try{
        prom.set_value(100);
        if(result.valid()){
            std::this_thread::sleep_for(300ms);
            auto sum = result.get();
            std::cout<<"Sum = "<<sum<<std::endl;
        }
    }catch(std::exception &ex){
        prom.set_exception(std::make_exception_ptr(ex));
    }
}