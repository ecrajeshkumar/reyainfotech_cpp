/*
std::apply → unpack tuple into function arguments.
    std::apply, which is a utility that lets you call a function with arguments unpacked from a std::tuple.

    Tuple unpacking → when you have data stored in a tuple and want to pass it to a function directly.
    Very handy in modern C++ when working with generic containers, callbacks, or variadic templates.

    std::apply(func, tuple) → expands the tuple into arguments and calls the function.
    In the first example, std::apply(greet, data) expands (101, "Rajesh", 95.5) into greet(101, "Rajesh", 95.5).
    In the second example, std::apply(sum, numbers) expands (10, 20, 30) into sum(10, 20, 30).

*/

#include <iostream>
#include <string>
#include <any>
#include <tuple>

// A simple function that takes multiple arguments
void greet(int id, const std::string_view name, double score){
    std::cout << "ID: " << id << ", Name: " << name << ", Score: " << score <<std::endl;
}

int main(){
    
    // Create a tuple with values
    std::tuple<int, std::string, double> data(100, "Rajesh", 95.5);

    // cal  greet() using std::apply
    std::apply(greet, data);

    auto sum = [](int i, int j, int k){
        return (i+j+k);
    };
    std::tuple<int, int, int> numbers(10,20,30);
    std::cout<<"sum = "<<std::apply(sum, numbers) <<std::endl;
    return 0;
}