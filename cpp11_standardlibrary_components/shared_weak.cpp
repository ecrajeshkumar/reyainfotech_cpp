#include <iostream>
#include <memory>
using namespace std;

struct Test {
    Test() { cout << "Constructed\n"; }
    ~Test() { cout << "Destroyed\n"; }
};

int main() {
    shared_ptr<Test> sp = make_shared<Test>();
    weak_ptr<Test> wp = sp; // observe sp, but don’t own

    cout << "use_count = " << sp.use_count() << "\n"; // 1

    if (auto locked = wp.lock()) { // safely get shared_ptr
        cout << "Object is alive\n";
    }

    sp.reset(); // destroy object

    if (wp.expired()) {
        cout << "Object is gone\n";
    }
}
