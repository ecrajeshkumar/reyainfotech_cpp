/*
    hey allow you to define templated constants or variables, not just classes or functions. This makes generic programming cleaner and avoids boilerplate.
*/

#include <iostream>

using namespace std;

// Define a variable template
template<typename T>
constexpr T pi = T(3.1415926535897932385);

template<typename T>
constexpr T kilo = T(1000);

int main() {
    cout << "pi as float  = " << pi<float> << endl;
    cout << "pi as double = " << pi<double> << endl;
    cout << "pi as long double = " << pi<long double> << endl;
    cout << "pi as long double = " << pi<int> << endl;

    cout << "kilo<int>    = " << kilo<int> << endl;
    cout << "kilo<double> = " << kilo<long double> << endl;
    cout << "kilo<double> = " << kilo<float> << endl;


}
