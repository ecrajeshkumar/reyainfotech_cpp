#include <iostream>

class Test {
public:
    void hello() { std::cout << "Hello!\n"; }
};

template <typename T>
class SmartPtr {
    T* ptr;
public:
    SmartPtr(T* p) : ptr(p) {}
    ~SmartPtr() { delete ptr; }

    T* operator->() { return ptr; }  // called when using ->
};

int main() {
    SmartPtr<Test> sp(new Test());
    sp->hello();  // calls SmartPtr::operator->(), returns Test*, then calls Test::hello()
                  // (sp.operator->())->hello();
}
