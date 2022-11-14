#include<iostream>
  
using namespace std;
  
class A {
 public:
   A & operator= (A &a) { 
       cout<<" base class assignment operator called "<<endl; 
       return *this;
   }
};
  
class B: public A {
    public:
    B & operator= (B &b) { 
        cout<<" Derived class assignment operator called "<<endl; 
        return *this;
    }
};

int main()
{
  B a, b;
    a.A::operator=(b); //calling base class assignment operator function 
                    // using derived class
    a = b;
  
  return 0;
}