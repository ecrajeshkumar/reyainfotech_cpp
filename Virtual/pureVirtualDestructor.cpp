/*
 *  Why a pure virtual function requires a function body?
 *  The reason is that destructors (unlike other functions) are not actually ‘overridden’, 
 *  rather they are always called in the reverse order of the class derivation. 
 *  This means that a derived class destructor will be invoked first, then the base class destructor 
 *  will be called. If the definition of the pure virtual destructor is not provided, 
 *  then what function body will be called during object destruction? Therefore the compiler and linker 
 * enforce the existence of a function body for pure virtual destructors.
*/

#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() = 0;
};
Base::~Base(){
    std::cout << "Pure virtual destructor is called";
}
class Derived : public Base {
public:
    ~Derived() { cout << "~Derived() is executed\n"; }
};
 
// Driver Code
int main(){
    Base* b = new Derived();
    delete b;
    return 0;
}