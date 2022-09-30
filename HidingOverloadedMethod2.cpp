#include <iostream>
using namespace std;
  
class Base {
public:
    void fun() { cout << "Base::fun() called"; }
};
  
class Derived : public Base {
public:
    //using Base::fun;
  
    void fun(char c) // Makes Base::fun() and Base::fun(int ) unhidden
    {
        cout << "Derived::fun(char c) called";
    }
};
  
// Driver Code
int main() {
    Derived d;
    d.fun(); // Works fine now
    return 0;
}