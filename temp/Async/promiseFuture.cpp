/*
    std::async create the shared state between a producer and a consumer.

    when we use future and promis only:
    std::promise<T> → producer side. It owns the shared state and can set a value.
    std::future<T> → consumer side. It’s obtained from the promise and can read the value.
    The shared state is created when we call promise.get_future().

    std::async is just a convenience wrapper that internally uses a promise/future pair.
    By using std::promise directly, you control when and how the value is set.
    This is useful when you want to integrate with custom threads, event loops, or callbacks.
*/

#include <future>
#include <iostream>

int main(){
    std::promise<int> data;
    std::future<int> result = data.get_future();
    data.set_value(10);
    std::cout<<"Data retrive from promise is "<< result.get()<<"\n";

    return 0;
}