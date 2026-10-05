/*
std::function is a general-purpose function wrapper.
 It can store and call any callable object — normal functions, lambdas, functors (objects with operator()), or even bind expressions.

  A callback is a function you hand over to another function, so it can invoke your code later when the right moment comes.
*/

#include <iostream>
#include <functional>  // std::function

// Normal function
int add(int a, int b) {
    return a + b;
}

int main() {
    // Store a normal function
    std::function<int(int,int)> f1 = add;
    std::cout << "add(10, 20) = " << f1(10, 20) << "\n";

    // Store a lambda
    std::function<int(int,int)> f2 = [](int x, int y){ return x * y; };
    std::cout << "lambda(5, 6) = " << f2(5, 6) << "\n";

    // Store a functor (object with operator())
    struct Functor {
        int operator()(int x, int y) { return x - y; }
    };
    std::function<int(int,int)> f3 = Functor();
    std::cout << "functor(15, 7) = " << f3(15, 7) << "\n";

    return 0;
}
