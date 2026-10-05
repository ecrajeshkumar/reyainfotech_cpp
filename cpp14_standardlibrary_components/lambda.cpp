/*
    C++14 was a relatively small update over C++11, but it introduced several useful language and library features such as 
    generic lambdas, variable templates, std::make_unique, and binary literals. 
*/



#include <iostream>
#include <memory>

using namespace std;

int main(){

    auto sum = [](int a, int b){
        return (a + b);
    };
    cout << "sum = " << sum(10, 20) << endl;
    //}(10,20);
    //cout<<"sum = "<<sum<<endl;

    // Lambdas can now use auto in parameter lists, making them type-generic.
    auto lambda = [](auto x, auto y) { return x + y; };
    cout<<"lambda = "<<lambda(20,20)<<endl;

    // Allows capturing by move or initializing captures directly.
    auto ptr = std::make_unique<int>(42);
    auto f = [p = std::move(ptr)] { return *p; };
    cout<<"f = "<<f()<<endl;

    



    

    return 0;
}