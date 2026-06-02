#include <iostream>
using namespace std;

class A{
    int x;
    int y;
    public:
    A(){
        x = 10;
        y = 20;
    }
    private:
    friend class B;    //friend class
    friend void print(A);
};
 
class B{
    int z = 30;
    public:
    void display(A &t){
        cout<<"from Class A::x = "<<t.x<<endl;
        //cout<<"from Class A::y = "<<y<<endl;
        cout<<"from Class B::z = "<<z<<endl;
    }
};

void print(A a){
    cout<<"from Class A::x = "<<a.x<<endl;
}
 
int main(){
    A _a;
    B _b;
    _b.display(_a);
    print(_a);
    return 0;
}