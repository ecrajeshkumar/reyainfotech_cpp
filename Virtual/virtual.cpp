#include <iostream>
  
using namespace std;

class Base {
public:
   /*virtual  void show() {*/
   void show() {
        cout << "Base::show() called";
    }
};

class Derived : public Base {
public:
    void show(){
        cout << "Derived::show() called";
    }
};
  
// Main driver method
int main()
{
    Derived d;
    Base& b = d;
    b.show();
  
    return 0;
}