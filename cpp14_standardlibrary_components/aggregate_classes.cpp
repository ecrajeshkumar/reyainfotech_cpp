#include <iostream>
using namespace std;

/*

    A class is considered an aggregate if:

    It has no user-declared constructors (including default, copy, or move constructors).

    It has no private or protected non-static data members.

    It has no virtual functions.

    It has no base classes.

    An aggregate class is a “plain struct-like” type that can be initialized directly with braces, without constructors.

struct Point {
    int x;
    int y;
};

int main() {
    Point p1{1, 2};   // aggregate initialization
    cout << "p1: (" << p1.x << ", " << p1.y << ")" << endl;
}

*/


// Aggregate with Default Member Initializers
// In C++14, the addition of default member initializers makes them more flexible and safer.
struct Point {
    int x = 0;   // default initializer
    int y = 0;   // default initializer
};

int main() {
    Point p1;              // uses defaults → x=0, y=0
    Point p2{10};          // x=10, y=0 (default for y)
    Point p3{5, 7};        // x=5, y=7 (explicit values override defaults)

    cout << "p1: (" << p1.x << ", " << p1.y << ")" << endl;
    cout << "p2: (" << p2.x << ", " << p2.y << ")" << endl;
    cout << "p3: (" << p3.x << ", " << p3.y << ")" << endl;

    return 0;
}


