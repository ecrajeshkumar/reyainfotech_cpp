#include <iostream>
using namespace std;

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