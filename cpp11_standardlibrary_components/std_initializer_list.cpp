#include <iostream>
#include <vector>

using namespace std;
/*
    std::initializer_list<T> is a special container type in C++ that represents a fixed sequence of values.
    Holds a sequence of elements of type T.
    Elements are immutable (you can’t modify them inside the initializer list).
    Typically created using brace-enclosed lists {}.
    Provides .begin(), .end(), and .size() for iteration.
*/
template<typename T>
void printInitializerList(std::initializer_list<T> list)
{
    std::vector<T> data;
    for (const auto & value: list){
        //value;
        std::cout << value << " ";
        data.push_back(value);
    }
    cout<<endl;
}
  
// Driver program
int main(){
    printInitializerList( {"One", "Two", "Three"} );
    int a=1,b=2,c=3,d=4,e=5;
    printInitializerList( {a,b,c,d,e} );
    printInitializerList( {1,2,3,4,5} );
    return 0;
}