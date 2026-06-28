/*
 * By default, all the functions defined inside the class are implicitly or automatically considered 
 * as inline except virtual functions. 
 *  Whenever a virtual function is called using a base class reference or pointer it cannot be 
 * inlined because the call is resolved at runtime, but whenever called using the object (without reference or pointer) of that class, can be inlined because the compiler knows the exact class of the object at compile time. 
*/ 
#include <iostream>
using namespace std;
 
class Base {
public:
    inline virtual void who() { cout << "I am Base\n"; }
};
class Derived : public Base {
public:
   inline void who() { cout << "I am Derived\n"; }
};
 
int main()
{
    // Part 1
    Base b;
    b.who();
 
    // Part 2
    Base* ptr = new Derived();
    ptr->who();
 
    return 0;
}