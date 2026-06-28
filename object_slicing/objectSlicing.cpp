#include <iostream>
using namespace std;

class Base {
    int x;
};
 
class Derived : public Base {
    int z;
};
 
int main() {
    Derived d;
    cout<<"size of Derived object: "<<sizeof(d)<<endl;
    Base b;
    cout<<"size of Base object: "<<sizeof(b)<<endl;
    // Object Slicing,
    // z and w of d are sliced off
    Base b1 = d;
    cout<<"size of Base object: "<<sizeof(b1)<<endl;
    
}