/*
Type inference means the compiler can deduce the type automatically instead of you writing it explicitly.
This makes code shorter, safer, and easier to maintain.

auto keyword : 
Lets the compiler deduce the type from the initializer.
decltype keyword :
Deduces the type of an expression without evaluating it.
Structured Bindings (C++17) :
    Allows unpacking tuples, pairs, or structs with type inference.
    std::pair<int, double> p{1, 2.5};
    auto [i, d] = p; // i = int, d = double

*/

#include <vector>

using std::vector;

int main() {
    const vector<int> v(1);
    auto a = v[0];        // a has type int
    decltype(v[0]) b = 1; // b has type const int&, the return type of
                          //   std::vector<int>::operator[](size_type) const
    auto c = 0;           // c has type int
    auto d = c;           // d has type int
    decltype(c) e;        // e has type int, the type of the entity named by c
    decltype((c)) f = c;  // f has type int&, because (c) is an lvalue
    decltype(0) g;        // g has type int, because 0 is an rvalue
}