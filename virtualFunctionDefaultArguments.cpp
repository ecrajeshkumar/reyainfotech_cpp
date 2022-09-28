/*
 *  Default arguments do not participate in the signature( function’s name, type, and order) of functions.
 *  So signatures of the ‘fun()‘ function in the base class and derived class are considered the same, 
 *  hence the ‘fun()‘ function of the base class is overridden. Also, the default value is used at 
 *  compile time. When the compiler sees an argument missing in a function call, it substitutes the 
 *  default value given. Therefore, in the above program, the value of x is substituted at compile-time, 
 *  and at run-time derived class’s ‘fun()‘ function is called. 
*/ 
#include <iostream>
using namespace std;

class Base{
  public:
    virtual void display(int x = 10){
        cout<<"from Base: x= "<<x<<endl;
    }
};
class Derived :public Base{
    public:
    /*void display(int x){*/
    void display(int x = 20){
        cout<<"from Derived: x= "<<x<<endl;
    }    
};
int main(){
    Base *bp = new Derived();
    bp->display();
    return 0;
}