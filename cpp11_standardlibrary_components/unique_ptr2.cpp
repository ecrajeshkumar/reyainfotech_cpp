#include <iostream>
#include <memory>
using namespace std;

struct Test {
    Test() { cout << "Constructed\n"; }
    ~Test() { cout << "Destroyed\n"; }
    void hello() { cout << "Hello from Test\n"; }
};

int main() {
     unique_ptr<Test> p1 = make_unique<Test>(); // preferred way
    //unique_ptr<Test> p1(new Test());
    p1->hello();

    // Transfer ownership
    unique_ptr<Test> p2 = std::move(p1);
    if (!p1) cout << "p1 is now empty\n";
    p2->hello();
}
