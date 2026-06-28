/*
*   It is a compile time cast.It does things like implicit conversions between types 
*   (such as int to float, or pointer to void*), and it can also call explicit conversion functions 
*   (or implicit ones).
*   static_cast performs a tight type checking
*/

#include <iostream>
#include <string>
using namespace std;

class Int{
  int x;
public:
Int(int x_ = 10):x(x_){
    cout << "Conversion constructor..." << endl;
    }
operator string(){
    cout << "Conversion Operator..." << endl;
    return to_string(x);
}
void display(){
    cout<<"x = "<<x<<endl;
}
};
class Base{
  public:
Base(){
    cout<<"Base..."<<endl;
}  
};
class Derived : public /*protected*/ /*private*/ Base{
public:
Derived(){
    cout<<"Derived..."<<endl;
}
};

int main()
{
    Int obj;
    obj.display();
    string str = obj;
    cout<<"str = "<<str<<endl;
    string str2 = static_cast<string>(obj);
    cout<<"str2 = "<<str2<<endl;
    
    obj = 20;
    obj.display();
    obj = static_cast<Int>(30);
    obj.display();
    cout<<"---------------------End--------------------------------"<<endl;
    
    float f = 3.5;
    int a = f; // this is how you do in C
    cout <<"a = "<<a<<"\t";
    int b = static_cast<int>(f);
    cout <<"b = "<<b<<endl;
    cout<<"---------------------End--------------------------------"<<endl;
    
    char c = 'a';
    int* q = (int*)&c; 
    //int* p = static_cast<int*>(&c); // pass at compile time, may fail at run 
    cout <<"c = "<<c<<"\t";
    cout <<"*q = "<<q<<endl;
    
    int i = 10;
    void *ptr = static_cast<void*>(&i);
    //cout<<"*ptr = "<<*ptr<<endl;
    int *ptr2 = static_cast<int*>(ptr);
    cout<<"*ptr2 = "<<*ptr2<<endl;
    cout<<"---------------------End--------------------------------"<<endl;
    
    Derived derv;
    Base *base = (Base*)&derv;
    Base *base2 = static_cast<Base*>(&derv); //use static_cast if inherit as public otherwise not allowed
    cout<<"---------------------End--------------------------------"<<endl;
    
    return 0;
}