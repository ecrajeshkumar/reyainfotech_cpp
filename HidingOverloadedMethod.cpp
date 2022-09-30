#include <iostream>
using namespace std;
  
class Base {
public:
    void fun() { cout << "Base::fun() called"; }
    void fun(int i) { cout << "Base::fun(int i) called"; }
};
  
class Derived : public Base {
public:
    void fun(int i, int k) { cout << "Derived::fun() called"; }
    int fun(char c) {
        cout << "Derived::fun(char c) called";
    }
};
  
// Driver Code
int main()
{
    Derived d;
    //d.fun();
    d.fun(5); // Compiler Error
    return 0;
}