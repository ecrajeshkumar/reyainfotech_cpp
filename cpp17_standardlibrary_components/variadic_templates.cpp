#include <iostream>


using namespace std;

// Template class
template<typename... Args>
auto sum(Args... args){
    // return (args + ... + 0);
    return (args + ... );
}

int main(){
    // Function calls
    cout << sum(11, 22, 33, 44, 55) <<"\n";

    return 0;
}