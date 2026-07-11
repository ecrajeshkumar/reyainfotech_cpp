#include <iostream>
#include <vector>

int main() {
    // 1. Basic initialization
    int a = 5;     // copy initialization
    int b(5);      // direct initialization
    int c{5};      // uniform initialization

    std::cout << "a=" << a << " b=" << b << " c=" << c << "\n";

    // 2. Narrowing conversion
    double d = 3.14;
    int x = d;     // allowed (value truncated)
    // int y(d);   // allowed
    // int z{d};  // ERROR: narrowing conversion prevented by {}

    // 3. Vexing parse problem
    int i1(3);     // fine
    int i2();      // looks like a function declaration, not a variable!
    int i3{};      // uniform initialization avoids this confusion

    // 4. Containers
    std::vector<int> v1(5, 10);   // 5 elements, each = 10
    std::vector<int> v2{5, 10};   // two elements: 5 and 10

    std::cout << "v1 size=" << v1.size() << " v2 size=" << v2.size() << "\n";

    return 0;
}
 