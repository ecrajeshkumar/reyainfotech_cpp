#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
 
class Test {
public:
    Test() { cout << "Constructor of Test " << endl; }
    ~Test() { cout << "Destructor of Test " << endl; }
};

void fun(int *ptr, int x) throw (int *, int){ // Dynamic Exception specification
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    /* Some functionality */
}

class Base {};
class Derived: public Base {}; 

/*int print() throw (int);*/
void print();

int main()
{
    cout<<"start11111111111111111111111"<<endl;
/*In C++, try/catch blocks can be nested. Also, an exception can be re-thrown using “throw; “. 
*/
    try {
        try {
            throw 20;
        }
        catch (int n) {
            cout << "Handle Partially "<<n<<endl;
            throw; // Re-throwing an exception
        }
    }
    catch (int n) {
        cout << "Handle remaining "<<n<<endl;
    }
    cout<<"end11111111111111Start2222222222222"<<endl;
    
/*When an exception is thrown, all objects created inside the enclosing try block are destroyed before the control is 
    transferred to the catch block.
*/
    try {
        Test t1;
        throw 10;
    }
    catch (int i) {
        cout << "Caught " << i << endl;
    }
    cout<<"end22222222222222Start33333333333333"<<endl;
    
    try {
       fun(NULL, 0);
    }
    catch(...) {
        cout << "Caught exception from fun()"<<endl;
    }
    
    
    cout<<"end3333333333333333333333Start444444444444444"<<endl;
 /*
    If both base and derived classes are caught as exceptions then catch block of derived class must appear before the base class. 
    If we put base class first then the derived class catch block will never be reached.
 */
    Derived d;
    try {
       throw d;
    }
    catch(Base b) {
        cout<<"Caught Base Exception"<<endl;
    }
    catch(Derived d) {
        cout<<"Caught Derived Exception"<<endl;
    }
    Derived d2;
    try {
       throw d2;
    }
    catch(Derived d) {
        cout<<"Caught Derived Exception"<<endl;
    }
    catch(Base b) {
        cout<<"Caught Base Exception"<<endl;
    }
    cout<<"end444444444444444444444Start5555555555555555555"<<endl;
/*
    It is compiler error to put catch all block before any other catch. The catch(...) must be the last catch block.
*/
/*    try{
       throw 10;
    }
    catch (...){
        cout << "default exceptionn";
    }
    catch (int param){
        cout << "int exceptionn";
    }*/
    
    
    cout<<"end5555555555555555Start6666666666666666666"<<endl;
    try{
        print();
    }
    catch(int num){
        cout<<"Exception caught without try statement only using throw..."<<num<<endl;
    }    
    
    return 0;
}

/*int print() throw (int) {*/
    void print() {
    throw 10;
/*    catch(int num){
        cout<<"Exception caught without try statement only using throw..."<<num<<endl;
    }*/
}




