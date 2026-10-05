#include <iostream>
using namespace std;
/*
    dynamic_cast is a C++ operator used for safe downcasting in class hierarchies when you have polymorphism 
    (i.e., at least one virtual function in the base class). It checks at runtime whether the cast is valid and 
    returns either the correct pointer/reference or nullptr (for pointers) if the cast fails.

    Works only with polymorphic types (classes with at least one virtual function).
    Used to cast a base class pointer/reference to a derived class pointer/reference.
    Performs a runtime check to ensure the cast is valid.
    Returns nullptr if the cast fails (for pointers).
    Throws std::bad_cast if the cast fails (for references).

    Base* b = new Derived();   // actually points to Derived
    Derived* d = dynamic_cast<Derived*>(b);   // casting of base to derived i.e downcasting
*/
// initialization of base class
class B {
    virtual void fun() {}
};
 
// initialization of derived class
class D : public B {};
 
// Driver Code
int main()
{
    B* b = new D; // Base class pointer
    D* d = dynamic_cast<D*>(b); // Derived class pointer
    if (d != NULL)
        cout << "works\n";
    else
        cout << "cannot cast B* to D*";
    getchar(); // to get the next character
    return 0;
}