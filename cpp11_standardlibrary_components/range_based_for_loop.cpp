/*
All standard library containers that have begin/end pairs will work with the range-based for statement.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Range-based for loop
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << "\n";

    int a[5] = {1, 2, 3, 4, 5};
// double the value of each element in a:
    for (int& x : a) {
        x *= 2;
        std::cout << x << " ";
    }
    std::cout << "\n";

// similar but also using type inference for array elements
    for (auto& x : a) {
        x *= 2;
        std::cout << x << " ";
    }
    std::cout << "\n";

    return 0;
}