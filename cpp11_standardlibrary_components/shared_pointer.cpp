/*
    A shared pointer keeps:
        A raw pointer to the resource.
        A reference counter (shared among all copies).
        When the last shared pointer is destroyed, the resource is deleted.
    T* operator->() is called whenever you use the arrow operator on your smart pointer object. 
    It returns the underlying raw pointer so the compiler can access the actual object’s members.
*/

#include <iostream>
using namespace std;

template <typename T>
class SharedPtr {
private:
    T* ptr;              // raw pointer to resource
    int* refCount;       // shared reference counter

public:
    // Constructor
    explicit SharedPtr(T* p = nullptr) : ptr(p), refCount(new int(1)) {
        cout<<"Constructor...\n";
    }

    // Copy Constructor
    SharedPtr(const SharedPtr& other) : ptr(other.ptr), refCount(other.refCount) {
        cout<<"Copy Constructor...\n";
        ++(*refCount);
    }

    // Copy Assignment
    SharedPtr& operator=(const SharedPtr& other) {
        cout<<"Copy Assignment...\n";
        if (this != &other) {
            // Decrement old counter
            release();

            // Copy new data
            ptr = other.ptr;
            refCount = other.refCount;
            ++(*refCount);
        }
        return *this;
    }

    // Destructor
    ~SharedPtr() {
        cout<<"Destructor...\n";
        release();
    }

    // Access operators
    T& operator*() { 
        cout<<"Access operators * ...\n";
        return *ptr; }
    T* operator->() {        // called when using -> // operator->() must return a pointer type (usually T*).
        cout<<"Access operators -> ...\n";
        return ptr; }

    // Utility
    int use_count() const { 
        cout<<"use_count...\n";
        return *refCount; }

private:
    void release() {
        cout<<"release...\n";
        if (--(*refCount) == 0) {
            delete ptr;
            delete refCount;
        }
    }
};


int main() {
    SharedPtr<int> sp1(new int(42));
    std::cout << "Count: " << sp1.use_count() << "\n"; // 1

    {
        SharedPtr<int> sp2 = sp1;
        std::cout << "Count: " << sp1.use_count() << "\n"; // 2
        std::cout << "Value: " << *sp2 << "\n";            // 42
    } // sp2 goes out of scope, count decrements

    std::cout << "Count: " << sp1.use_count() << "\n"; // 1
}
