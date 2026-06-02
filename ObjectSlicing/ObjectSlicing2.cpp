#include <iostream>
using namespace std;

class Base {
protected:
    int i; 
public:
    Base(int a) { i = a; }
    virtual void display() {
        cout << "I am Base class object, i = " << i << endl;
    }
};

class Derived : public Base {
    int j; 
public:
    Derived(int a, int b) : Base(a){
        j = b;
    }
    virtual void display(){
        cout << "I am Derived class object, i = " << i
             << ", j = " << j << endl;
    }
};

// object is passed by value
/*void somefunc(Base obj) { obj.display(); }*/
// object is passed by refrence
/*void somefunc(Base &obj) { obj.display(); }*/
// object is passed by pointer
void somefunc(Base *obj) { obj->display(); }
 
int main() {
    Base b(33);
    Derived d(45, 54);
    /*somefunc(b);*/
    somefunc(&b);
 // Object Slicing, the member j of d is sliced off
    /*somefunc(d);*/
    somefunc(&d);
    return 0;
}