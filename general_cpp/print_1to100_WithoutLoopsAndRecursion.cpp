#include <iostream>

using namespace std;

class A{
    static int count;
    public:
    A(){
        cout<<count++<<", ";
    }
};
int A::count = 1;

int main(){
    A a[100];

    cout<<"\n2nd *********************************"<<endl;
    
    int count = 0;
    update:
        ++count;
        cout<<count<<", ";
        if(count == 100)
            return 0;
        goto update;

    return 0;
}