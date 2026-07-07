/*
    Functions declared with auto can deduce return types without explicit trailing return type.
*/

#include <iostream>
#include <memory>

using namespace std;

//auto add(int a, int b) { return a + b; }

/*
    In standard C++14, you cannot use auto directly in a function parameter list like that.
    That syntax (auto in parameters) is part of C++20 concepts (or enabled earlier with compiler extensions like -fconcepts in GCC).

    If you compile with C++20 enabled (-std=c++20), then below code works:

    */
//auto add(auto a, auto b) { return a + b; }

template <typename T, typename U>
auto add(T a, U b) {
    return a + b;
}


int main(){

    cout<<"add = "<<add(10,20)<<endl;

    cout<<"add = "<<add(10.2,20)<<endl;

    cout<<"add = "<<add(10,20.2)<<endl;

    cout<<"add = "<<add(10.2,20.2)<<endl;



    return 0;
}