/*

    std::make_unique<T>(args...) constructs an object of type T and returns a std::unique_ptr<T>.
    It’s safer than using new directly because it avoids memory leaks and exception-safety issues.

    Unlike std::make_shared, it was added in C++14 (not available in C++11).
    This is especially useful when you want exclusive ownership of a resource — only one pointer manages it, and it gets destroyed 
    automatically when the pointer goes out of scope.

    std::make_unique<T>(args...) always returns a std::unique_ptr<T>.

    std::make_unique<T>(args...) constructs an object of type T using the arguments you pass.

    It then wraps that object inside a std::unique_ptr<T>.

    The returned pointer has exclusive ownership of the object — meaning only one unique_ptr can own it at a time.

*/

#include <iostream>
#include <memory>   // for std::unique_ptr and std::make_unique
using namespace std;

struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {
        cout << "Point constructed: (" << x << ", " << y << ")" << endl;
    }
    ~Point() {
        cout << "Point destroyed: (" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Create a unique_ptr using std::make_unique
    auto p = std::make_unique<Point>(10, 20);

    cout << "Accessing Point: (" << p->x << ", " << p->y << ")" << endl;

    // Ownership is unique — cannot copy
    // auto q = p; // ❌ error: unique_ptr cannot be copied
    auto q = std::move(p); // ✅ transfer ownership

    cout << "Point via q: (" << q->x << ", " << q->y << ")" << endl;

    // No need to delete manually — unique_ptr cleans up automatically
    return 0;
}

