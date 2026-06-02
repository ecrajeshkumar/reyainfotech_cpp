/*
 * An interface does not have implementation of any of its methods, it can be considered as a collection 
 * of method declarations. In C++, an interface can be simulated by making all methods as pure virtual.
 * We can think of Interface as header files in C++, like in header files we only provide the body 
 * of the class that is going to implement it.
*/ 
#include<iostream>
using namespace std;
 
// An abstract class with constructor
class Base{
protected:
    int x;
public:
virtual void fun() = 0;
Base(int i) {
    x = i;
    cout<<"Constructor of base called\n";
    }
virtual ~Base(){ cout<<"Destructor of base called\n";}
};
 
class Derived: public Base{
    int y;
public:
    Derived(int i, int j):Base(i) { 
        cout<<"Constructor of Derived called\n";
        y = j; }
    void fun() { cout << "x = " << x << ", y = " << y<<'\n'; }
    ~Derived(){ cout<<"Destructor of Derived called\n";}
};

int main(void){
    Derived d(4, 5);
    d.fun();
   
  //object creation using pointer of base class
    Base *ptr = new Derived(6,7);
    ptr->fun();
    
    delete ptr;
    return 0;
}