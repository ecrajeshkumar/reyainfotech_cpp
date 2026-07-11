/*
Uses curly braces {} for initialization instead of () or =.
Provides a consistent syntax for initializing variables, arrays, structs, classes, and containers.


*/

#include <iostream>
#include <vector>
#include <string>

struct Point {
    int x, y;
};

class MyClass {
    std::vector<int> data;
public:
    // Constructor using initializer_list
    MyClass(std::initializer_list<int> list) {
        for (auto val : list) data.push_back(val);
    }
    void print() {
        for (auto val : data) std::cout << val << " ";
        std::cout << "\n";
    }
};

int main() {
    // Uniform initialization for basic types
    int a{10};       // instead of int a = 10;
    double b{3.14};  // instead of double b = 3.14;

    // Struct initialization
    Point p{5, 7};   // instead of Point p = {5, 7};

    // Vector initialization
    std::vector<int> v{1, 2, 3, 4, 5};

    // Class with initializer_list constructor
    MyClass obj{10, 20, 30, 40};
    obj.print();

    return 0;
}

