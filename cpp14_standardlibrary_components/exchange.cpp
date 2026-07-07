#include <iostream>
#include <utility>   // for std::exchange
using namespace std;

int main() {
    int a = 10;

    // Replace 'a' with 20, return old value
    int old = std::exchange(a, 20);

    cout << "Old value = " << old << endl;
    cout << "New value = " << a << endl;

    // Example with string
    string s = "Hello";
    string old_s = std::exchange(s, "World");

    cout << "Old string = " << old_s << endl;
    cout << "New string = " << s << endl;

    return 0;
}
