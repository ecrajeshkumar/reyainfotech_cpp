#include<iostream>
using namespace std;
 
class Base {
public:
    virtual int fun(int i) {
        cout << "Base::fun(int i) called";
        return i;
    }
};
 
class Derived: public Base {
private:
    int fun(int x)   {
        cout << "Derived::fun(int x) called";
        return x;
    }
};
 
int main() {
/*    Derived d;
    d.fun(1);*/
    
    Base *ptr = new Derived;
    ptr->fun(10);
    
    return 0;
}