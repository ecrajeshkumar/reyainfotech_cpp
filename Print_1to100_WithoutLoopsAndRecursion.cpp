#include <iostream>

using namespace std;

class A{
    static int count;
    public:
    A(){
        cout<<count++<<endl;
    }
};
int A::count = 1;

int main(){
    A a[10];
    cout<<"*********************************"<<endl;
    
    int count = 0;
    update:
        ++count;
        cout<<count<<endl;
        if(count == 100)
            return 0;
        goto update;

    return 0;
}