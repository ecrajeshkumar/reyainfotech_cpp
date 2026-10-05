/*
It’s designed to solve a very specific problem: cyclic references when using shared_ptr.
It does not increase the reference count.
weak_ptr → observer, no ownership, prevents cycles.

Imagine two objects that hold shared_ptrs to each other:
struct B;
struct A {
    std::shared_ptr<B> b;
};
struct B {
    std::shared_ptr<A> a;
};

Both objects keep each other alive forever → memory leak (reference cycle).
Solution: make one of them a weak_ptr. That way, the cycle is broken.

*/
//=====================================================================================================================
#include <memory>

struct B; // forward declaration

struct A {
    std::shared_ptr<B> b;  // strong ownership
};

struct B {
    std::shared_ptr<A> a;  // strong ownership
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();
    a->b = b;
    b->a = a;
} // ❌ Leak: both keep each other alive, ref count never hits 0

/*
    Here, a owns b and b owns a. Their reference counts never drop to zero → memory leak.
*/

//====================================================================================================================
// The Solution (use weak_ptr for one side)
#include <iostream>
#include <memory>

struct B; // forward declaration

struct A {
    std::weak_ptr<B> b;  // weak ownership
};

struct B {
    std::shared_ptr<A> a;  // strong ownership
};

int main() {
    auto a = std::make_shared<A>();
    auto b = std::make_shared<B>();

    a->b = b;   // weak_ptr observes b
    b->a = a;   // shared_ptr owns a

    std::cout << "use_count of a: " << a.use_count() << "\n";
    std::cout << "use_count of b: " << b.use_count() << "\n";
} // ✅ Both destroyed correctly
