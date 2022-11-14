#include <iostream>

using namespace std;

template<typename T>
void printInitializerList(std::initializer_list<T> list)
{
    for (const auto & value: list){
        value;
        std::cout << value << " ";
        
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