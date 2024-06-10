#include <iostream>
 
using namespace std;
 
class Test {
public:
//error: member 'fun' cannot be declared both 'virtual' and 'static'
    virtual static void fun() {}
//error: static member function 'static void Test::fun()' cannot have cv-qualifier    
    static void fun() const {}
};

int main(){
    
    return 0;
}