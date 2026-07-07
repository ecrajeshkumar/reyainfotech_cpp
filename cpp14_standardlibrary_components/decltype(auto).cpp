/*
    Purpose: Used in function return type deduction. It tells the compiler: deduce the return type exactly as decltype(expr) would.
    Behavior: Preserves references and constness, unlike plain auto which strips them.
*/
/*
    Use decltype when you want to declare a variable type based on an expression.

    Use decltype(auto) when you want a function to deduce its return type exactly as decltype(expr) would, including references.
*/

#include <iostream>

int x = 10;

auto getAuto() {
    return (x);   // return type deduced as int (reference lost)
}

decltype(auto) getDecltypeAuto() {
    return (x);   // return type deduced as int& (reference preserved)
}

int main() {
    getDecltypeAuto() = 20;  // modifies x
    cout << x << endl;       // prints 20
}



