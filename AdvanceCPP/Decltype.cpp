/*
*   decltype Keyword: It inspects the declared type of an entity or the type of an expression. 
*   ‘auto’ lets you declare a variable with a particular type whereas decltype lets you extract the type from the variable so 
*   decltype is sort of an operator that evaluates the type of passed expression.
*   Decltype gives the type information at compile time while typeid gives at runtime.
*   So, if we have a base class reference (or pointer) referring to (or pointing to) a derived class object, 
*   the decltype would give type as base class reference (or pointer, but typeid would give the derived type reference 
*   (or pointer).
*/
#include <bits/stdc++.h>
using namespace std;

// A generic function which finds minimum of two values
// return type is type of variable which is minimum
template <class A, class B>
auto findMin(A a, B b) -> decltype(a < b ? a : b) {
    return (a < b) ? a : b;
}

int fun1() { return 10; }
char fun2() { return 'g'; }
 
int main(){
    // Data type of x is same as return type of fun1()
    // and type of y is same as return type of fun2()
    decltype(fun1()) x = 10;
    decltype(fun2()) y = 20;
 
    cout << typeid(x).name() << " x: "<<x<<endl;
    cout << typeid(y).name() << " y: "<<y<<endl;
    cout<<"End************************"<<endl;
    
    int z = 5;
    // j will be of type int : data type of z
    decltype(z) j = z + 5;
    cout << "typeid of j: "<<typeid(j).name()<<endl;
    cout<<"End************************"<<endl;
    
    // This call returns 3.44 of double type
    cout << findMin(4, 3.44) << endl;
    // This call returns 3 of double type
    cout << findMin(5.4, 3) << endl;
    cout<<"End************************"<<endl;
 
    return 0;
}