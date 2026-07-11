
#include <iostream>
#include <vector>
#include <memory>
#include <functional>

using namespace std;

int main() {
    // Basic Lambda
    auto add = [](int a, int b) { return a + b; }; // lambda
    cout << "Sum = " << add(10, 20) << "\n";

    // Lambda with capture
    int x = 5;
    auto multiply = [x](int y) { return x * y; }; // captures
    cout << "Product = " << multiply(10) << "\n";
    
    // Lambda with reference capture
    int z = 3;
    auto increment = [&z]() { z++; }; // captures by reference
    increment();
    cout << "Incremented value = " << z << "\n";

    // Lambda with mutable
    int count = 0;
    auto increment_count = [count]() mutable { 
        count++; 
        cout << "Incremented inside lambda count = " << count << "\n";
        }; // captures by value, but mutable
    increment_count();
    cout << "Incremented count = " << count << "\n";
    
    // Lambda with auto parameters (C++14)
    auto generic_lambda = [](auto a, auto b) { return a + b; };
    cout << "Generic Sum = " << generic_lambda(1, 2) << "\n";
    
    // Lambda with return type
    auto divide = [](double a, double b) -> double { return a / b; };
    cout << "Division = " << divide(10.0, 2.0) << "\n";

    // Lambda as a function parameter
    auto apply = [](int a, int b, auto func) { return func(a, b); };
    cout << "Applied Sum = " << apply(3, 4, add) << "\n";

    // Lambda with no capture
    auto no_capture = []() { return 42; }; 
    cout << "No Capture = " << no_capture() << "\n";

    // Lambda with capture by reference and value
    int a = 10, b = 20;
    auto capture_lambda = [&a, b]() { return a + b; };
    cout << "Captured Sum = " << capture_lambda() << "\n";

    vector<int> v = {1, 2, 3, 4, 5};
    // Use lambda with for_each
    for_each(v.begin(), v.end(), [](int x) {
        cout << x * x << " ";
    });
    cout << "\n";

    // Lambda with std::function
    std::function<int(int, int)> func = [](int x, int y) { return x * y; };
    cout << "Function Product = " << func(5, 6) << "\n";

    // C++17 (2017)
    // Capture by move: [x = std::move(obj)] allows moving into the lambda.
    // auto move_lambda = [x = std::move(obj)] { };
    auto ptr = std::make_unique<int>(42);
    auto f = [p = std::move(ptr)](){ return *p; };
    std::cout << f() << "\n"; // prints 42


    // C++20 (2020)
    // Lambda template parameters: auto in parameter list allows generic lambdas.
    // auto generic_lambda = [](auto a, auto b) { return a + b; };



    return 0;
}
