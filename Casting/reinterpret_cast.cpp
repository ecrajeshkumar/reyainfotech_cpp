/*
*   It is used to convert a pointer of some data type into a pointer of another data type, 
*   even if the data types before and after conversion are different.
*   It does not check if the pointer type and data pointed by the pointer is same or not.
*   It doesn’t have any return type. It simply converts the pointer type.
*   reinterpret_cast is a very special and dangerous type of casting operator. 
*   And is suggested to use it using proper data type i.e., 
*   (pointer data type should be same as original data type).
*   It can typecast any pointer to any other data type.
*   It is used when we want to work with bits.
*   If we use this type of cast then it becomes a non-portable product. 
*   So, it is suggested not to use this concept unless required.
*   It is only used to typecast any pointer to its original type.
*   Boolean value will be converted into integer value i.e., 0 for false and 1 for true.
*/

#include <iostream>
using namespace std;

struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};

class A{
public:
    void display(){
        cout<<"from A"<<endl;
    }
};
class B{
public:
    void display(){
        cout<<"from B"<<endl;
    }
};

int main()
{
    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    cout << *p << endl;
    cout << *ch << endl;
    cout << p << endl;
    cout << ch << endl;
    cout<<"-----------------End------------------------"<<endl;
    
    mystruct s;
    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;
    int* ptr = reinterpret_cast<int*>(&s);
    cout << sizeof(s) << endl;
    cout << *ptr << endl;
    cout<<"-----------------End------------------------"<<endl;
    
    A *a = new A();
    //B *b = reinterpret_cast<B*>(a);
    B *b = (B*)a;
    b->display();
    cout<<"-----------------End------------------------"<<endl;
    
    return 0;
}

