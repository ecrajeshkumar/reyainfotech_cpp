#include <iostream>
using namespace std;
/*
*	when a class has a private destructor, only dynamic objects(pointer object) of that class can be created. Following is a way to create classes with private destructors and have a function as a friend of the class. The function can only delete the objects.  
*/
// A class with private destructor
class Test {
private:
    ~Test() {cout<<"private destructor..."<<endl;}
  
public:
    friend void destructTest(Test*);
};
  
// Only this function can destruct objects of Test
void destructTest(Test* ptr) { delete ptr; }
  
int main()
{
    // create an object
    Test* ptr = new Test;
    
    //delete ptr;
    
    // destruct the object
    destructTest(ptr);
  
    return 0;
}