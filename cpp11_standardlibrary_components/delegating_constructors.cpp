/******************************************************************************



*******************************************************************************/
#include <iostream>
#include <string>

// 1. Delegating Constructors
class Rectangle {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {
        std::cout << "Rectangle(" << width << ", " << height << ")\n";
    }
    Rectangle() : Rectangle(10, 10) {}             // delegates
    Rectangle(int size) : Rectangle(size, size) {} // delegates
};

// 2. Defaulted Constructor
class Point {
    int x, y;
public:
    Point() = default;  // compiler generates default constructor
    Point(int a, int b) : x(a), y(b) {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

// 3. Deleted Constructor
class NonCopyable {
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete; // disallow copy
    NonCopyable& operator=(const NonCopyable&) = delete; // disallow assignment
};

// 4. Member Initializers (In-Class Initialization)
class Config {
    int timeout = 30;   // default value
    bool enabled = true;
public:
    void show() const {
        std::cout << "Config(timeout=" << timeout
                  << ", enabled=" << std::boolalpha << enabled << ")\n";
    }
};

// 5. Inheriting Constructors
class Base {
public:
    Base(int x) {
        std::cout << "Base(" << x << ")\n";
    }
    Base(const std::string& s) {
        std::cout << "Base(" << s << ")\n";
    }
};

class Derived : public Base {
    using Base::Base;  // inherits constructors
public:
    // Define your own constructor
    Derived(double d) : Base(static_cast<int>(d)) {
        std::cout << "Derived(double " << d << ")\n";
    }

    // Another custom constructor
    Derived(int x, int y) : Base(x + y) {
        std::cout << "Derived(" << x << "," << y << ")\n";
    }
};

int main() {
    // 1. Delegating constructors
    Rectangle r1;          // calls Rectangle()
    Rectangle r2(5);       // calls Rectangle(int)
    Rectangle r3(3, 4);    // calls Rectangle(int,int)

    // 2. Defaulted constructor
    Point p1;              // compiler-generated default
    Point p2(7, 8);

    // 3. Deleted constructor
    NonCopyable nc1;
    // NonCopyable nc2 = nc1; // ERROR: copy constructor deleted

    // 4. Member initializers
    Config cfg;
    cfg.show();

    // 5. Inheriting constructors
    Derived d1(42);         // calls Base(int)
    Derived d2("Hello");   // calls Base(string)
    Derived d3(3.14);      // calls Derived(double) 
    Derived d4(1, 2);      // calls Derived(int, int)
    


    return 0;
}