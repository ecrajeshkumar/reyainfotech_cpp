  
#include <iostream>
using namespace std;

int main() {
    if(1){
        label_1: cout<<"if..."<<endl;
        goto label_2;
    }else{
        label_2: cout<<"else..."<<endl;
        //goto label_1;
    }
    return 0;
}