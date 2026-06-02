#include <iostream>
using namespace std;

class A {
private:
    int x;
protected:
    int y;
public:
    A() { x = 1; y = 2; }
    friend void show();
};

class B : public A {
private:
    int a;
protected:
    int b;
public:
    B() { a = 10; b = 20; }
};
  
void show(){
    B b;
    cout<<"b.x: = "<<b.x<<endl;
    cout<<"b.y: = "<<b.y<<endl;
  
    // Can't access private member declared in class 'B'
    //cout<<"b.a: = "<<b.a<<endl;
    cout<<"b.b: = "<<b.b<<endl;
}
  
int main() {
    show();
    return 0;
}