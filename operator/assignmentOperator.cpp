#include<iostream>
  
using namespace std;
  
class Base {
 public:
   Base & operator= (Base &a) { 
       cout<<" base class assignment operator called "<<endl; 
       return *this;
   }
   void display() { cout<<" base class display function called "<<endl; }
};
  
class Derived: public Base {
    public:
    Derived & operator= (Derived &b) { 
        cout<<" Derived class assignment operator called "<<endl; 
        return *this;
    }
    void display() { cout<<" Derived class display function called "<<endl; }
};

int main()
{
  Derived d1, d2;
    d1.Base::operator=(d2); //calling base class assignment operator function using derived class object
    d1.display();
    d1 = d2;
    d1.display();
  
  return 0;
}