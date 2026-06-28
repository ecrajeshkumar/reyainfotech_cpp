/*

The normal if statement condition is executed at run time, so C++17 introduced this new if constexpr statement. 
The main difference is that if constexpr is evaluated at compile time. 
if constexpr:  its main importance goes with template code.
*/


// C++ 17 code to demonstrate if constexpr 
  
#include <iostream> 
#include <string> 
#include <type_traits> 
using namespace std; 
  
// Template Class 
template <typename T> 
auto length(T const& value) { 
    // Check the condition with if 
    // statement whether T is an 
    // integer or not 
    if constexpr(is_integral<T>::value) { 
        return value; 
    } 
    else { 
        return value.length(); 
    } 
} 

// Driver Code 
int main() 
{ 
    int n{ 10 }; 
  
    string s{ "abc" }; 
  
    cout << "n = " << n 
         << " and length = "
         << length(n) << endl; 
  
    cout << "s = " << s 
         << " and length = "
         << length(s) << endl; 
}