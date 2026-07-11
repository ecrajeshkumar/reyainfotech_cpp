/******************************************************************************

Why Introduced in C++11:
Traditional syntax (ReturnType func(Args...)) places the return type before parameters, so parameter names aren’t yet in scope.
Templates often need return types that depend on parameter expressions (e.g., decltype(a+b)).
Trailing return types solve this scoping problem.

The use of the "auto" keyword in this case is just part of the syntax and does not perform automatic type deduction in C++11. 
However, starting with C++14, the trailing return type can be removed entirely and the compiler will deduce the return type automatically.

If you’re writing generic functions in C++11 or later, especially with templates, always prefer trailing return types when 
the return type depends on parameters. For simple functions, it’s optional but keeps your code consistent with modern C++ style.

*******************************************************************************/
#include <iostream>

using namespace std;

// Trailing return type
auto add(int a, int b) -> int {
        return a + b;
    }

template<typename T1, typename T2>
auto sum(const T1& a, const T2& b) -> decltype(a + b) {
    return a + b;
}

int main() {
    
    int sum = add(3, 4); // sum = 7
    cout << "Sum: " << sum << std::endl;

    double result = sum(3.5, 2); // result = 5.5
    cout << "Result: " << result << std::endl;
    
    return 0;
}



