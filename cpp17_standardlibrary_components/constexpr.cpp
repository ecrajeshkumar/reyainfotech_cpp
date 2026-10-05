/*
    constexpr bridges compile-time computation and runtime flexibility.
    constexpr means the function or variable can be evaluated at compile time if given constant expressions.
    square(5) is known at compile time → compiler replaces it with 25.
    square(n) depends on user input → evaluated at runtime.
    This dual behavior makes constexpr powerful: it works both at compile time and runtime.
*/

#include <iostream>
#include <string>

constexpr int square(int num){
    return num*num;
}

int factorial(int num){
    return (num <= 1) ? 1 : num*factorial(num-1)
}

int main(){
    // compile-time constant
    constexpr  int val = square(5); // Evalute at compile time
    std::cout<<"Compile-time square: "<< val << std::endl;

    // Run-time evalution (input not known at compile time)
    int n;
    std::cout<< "Enter number: \n";
    std::cin>>n;
    std::cout<< "Run-time square: " << square(n) << std::endl;

    std::cout<< "Run-time square: " << factorial(5) << std::endl;
    return 0;
}