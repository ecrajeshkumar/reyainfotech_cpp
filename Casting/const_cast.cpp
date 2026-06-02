/*
 * const_cast is used to cast away the constness of variables.
 */

#include <iostream>

using namespace std;

class ConstCast{
    int data;
    const int num;
public:
    ConstCast():data(10),num(10){
    }
    void display(){
        cout<<"data: "<<data<<"\t";
        cout<<"num: "<<num<<endl;
    }
    void update() const{
        //data = 20;
/*
 * const_cast can be used to change non-const class members inside a const member function.
*/
    (const_cast<ConstCast*>(this))->data = 20;
    
    //(const_cast<ConstCast*>(this))->num = 20;
    }
};

void print(int *ptr_){
    *ptr_ = *ptr_ + 10;
}
int main(int argc, char **argv)
{
    ConstCast constCast;
    constCast.display();
    constCast.update();
    cout<<"After update through constMemberFunction...\n";
    constCast.display();
    cout<<"______________________End__________________________"<<endl;
    
    //int data = 10;
    const int data = 10;
    const *ptr = &data;
    cout<<"Before *ptr: "<<*ptr<<" data: "<<data<<endl;
    //print(ptr);
/*
 *  const_cast can be used to pass const data to a function that doesn’t receive const. 
*/    
    print(const_cast<int*>(ptr));
    cout<<"After *ptr: "<<*ptr<<" data: "<<data<<endl;
    cout<<"______________________End__________________________"<<endl;
    
/*
 *  const_cast is considered safer than simple type casting. It’safer in the sense that the casting won’t happen if the type of cast is not same as original object.
*/ 
    int num = 100;
    int const *ptr2 = &num;
    cout<<*ptr2<<endl;
    //char *ch = const_cast<char*>(ptr2);  //Compiler error
    char *ch = (char*)(ptr2);
    cout<<ch;
    cout<<"______________________End__________________________"<<endl;
    
/*
 * const_cast can also be used to cast away volatile attribute.
*/
    int a = 10;
    const volatile int* b= &a;
    cout<<"Typeid of b = "<<typeid(b).name()<<endl;
    int *c = const_cast<int*>(b);
    cout<<"Typeid of c = "<<typeid(c).name()<<endl;
    cout<<"______________________End__________________________"<<endl;
    
    //const int a1 = 40;
    int a1 = 40;
    const int* b1 = &a1;
    char* c1 = (char *)(b1);
    //char* c1 = const_cast<char*>(b1);  //Compile Error
    *c1 = 'A';
    cout<<"&c1= "<<&c1<<" c1= "<<c1<<endl;
    cout<<"&b1= "<<&b1<<" b1= "<<*b1<<endl;
    cout<<"&a1= "<<&a1<<" a1= "<<a1<<endl;
    cout<<"______________________End__________________________"<<endl;
    
    
	return 0;
}
