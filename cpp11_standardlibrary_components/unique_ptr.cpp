/*
    unique_ptr expresses exclusive ownership of a dynamically allocated object. 
    It automatically deletes the object when the unique_ptr goes out of scope, ensuring no leaks.

    Exclusive ownership → only one unique_ptr can own a resource at a time.
    Non-copyable → you cannot copy a unique_ptr.
    Movable → you can transfer ownership using std::move.
    Automatic cleanup → calls delete (or delete[]) when destroyed.
    Custom deleters → you can specify how the resource should be freed.

    Prevents memory leaks.
    Expresses clear ownership semantics.
    Safer than raw pointers.
    Lightweight compared to shared_ptr (no reference counting overhead).
    std::unique_ptr is the go‑to smart pointer when you want one owner of a resource, automatic cleanup, 
    and no accidental copies.
    =======================================================================================
    | Feature | ``unique_ptr`` | ``shared_ptr`` |
    | ---     | ---            | ---            |
    | Ownership | Exclusive (only one owner) | Shared (multiple owners) |
    | Copyable | ❌ No (copy disabled) | ✅ Yes (increments ref count) |
    | Movable | ✅ Yes (ownership transfer) | ✅ Yes (shares ownership) |
    | Reference Counting | ❌ None | ✅ Maintains ref count |
    | Overhead | Very low | Higher (atomic ref count) |
    | Best Use Case | Single owner, lightweight RAII | Multiple owners, shared resources |

    =======================================================================================
    Start with unique_ptr.
    Switch to shared_ptr only if you truly need shared ownership.
    Switching from a unique_ptr to a shared_ptr is straightforward in modern C++. 
    The standard library provides a constructor for shared_ptr that takes ownership from a unique_ptr via move semantics.

    unique_ptr<Test> up = make_unique<Test>();
    up->hello();

    // Convert to shared_ptr
    shared_ptr<Test> sp = std::move(up);

    if (!up) cout << "unique_ptr is now empty\n";
    sp->hello();

    // Copy shared_ptr (reference count increases)
    shared_ptr<Test> sp2 = sp;
    cout << "use_count = " << sp.use_count() << "\n";
    =======================================================================================

    A unique_ptr:
    Owns a raw pointer.
    Deletes it when the smart pointer goes out of scope.
    Cannot be copied (ownership is unique).
    Can be moved (ownership transfer).
*/

#include <iostream>

template <typename T>
class UniquePtr {
private:
    T* ptr;

public:
    // Constructor
    explicit UniquePtr(T* p = nullptr) : ptr(p) {}

    // Destructor
    ~UniquePtr() {
        delete ptr;
    }

    // Delete copy constructor & copy assignment (no copying allowed)
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Move constructor
    UniquePtr(UniquePtr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;          // free current resource
            ptr = other.ptr;     // transfer ownership
            other.ptr = nullptr;
        }
        return *this;
    }

    // Access operators
    T& operator*() { return *ptr; }
    T* operator->() { return ptr; }

    // Utility
    T* get() const { return ptr; }
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
};

struct Test {
    void hello() { std::cout << "Hello from Test\n"; }
};

int main() {
    UniquePtr<Test> up1(new Test());
    up1->hello();

    // Transfer ownership
    UniquePtr<Test> up2 = std::move(up1);
    if (!up1.get()) std::cout << "up1 is empty\n";
    up2->hello();

    // Reset with new object
    up2.reset(new Test());
    up2->hello();

    // Release ownership
    Test* raw = up2.release();
    if (!up2.get()) std::cout << "up2 is empty\n";
    delete raw; // manual cleanup
}






