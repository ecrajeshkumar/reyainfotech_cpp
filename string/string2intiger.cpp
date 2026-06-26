#include <iostream>
#include <string>

using namespace std;

int main(){
    string str = "12345";
    try{
        int value = stoi(str);
        cout<<"Given string is "<<str<<" and its intiger conversion is "<<value;
    }catch(exception& ex){
        cout<<ex.what();
    }

    return 0;
}