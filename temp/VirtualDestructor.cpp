/*
 * Any time you have a virtual function in a class, you should immediately add a virtual destructor 
 * (even if it does nothing). This way, you ensure against any surprises later.
 * if there is virtual then object should create through new operator. 
*/
#include<iostream>
using namespace std;
 
class base {
  public:
    base()
    { cout << "Constructing base\n"; }
    virtual ~base()
    { cout << "Destructing base\n"; }    
};
 
class derived : public base {
  public:
    derived()    
    { cout << "Constructing derived\n"; }
     ~derived()
    { cout << "Destructing derived\n"; }
};
 
int main()
{
//   derived *d = new derived(); 
  derived d;
  base *b = &d;
  delete b;
  //getchar();
  return 0;
}