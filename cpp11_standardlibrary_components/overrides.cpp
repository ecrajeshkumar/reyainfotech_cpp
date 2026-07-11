/*
If you wrote void show(double x) without override, the compiler would silently treat it as a new function 
(not overriding Base::show(int)), which could lead to bugs. With override, you get a compile-time error.
*/

#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Base display\n";
    }

    virtual void show(int x) {
        std::cout << "Base show: " << x << "\n";
    }
};

class Derived : public Base {
public:
    void display() override {   // correctly overrides Base::display
        std::cout << "Derived display\n";
    }

    // If you miss the parameter type, compiler error will catch it
    void show(double x) override {   // ERROR: no matching base function
        std::cout << "Derived show: " << x << "\n";
    }
};

int main() {
    Base* b = new Derived();
    b->display(); // Calls Derived::display
    b->show(10);  // Calls Base::show(int)
    
    delete b;
    return 0;
}