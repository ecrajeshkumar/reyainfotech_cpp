/*
C++11 also adds the ability to prevent inheriting from classes or simply preventing overriding methods in derived classes.
*/

struct Base final {
    // ...
};

// ill-formed because the class Base has been marked final
struct Derived : public Base {
    // ...
};

struct Base {
    virtual void foo() final;
};

struct Derived : public Base {
    void foo(); // ill-formed because the virtual function Base::foo has been marked final
};

/*
In this example, the virtual void foo() final; statement declares a new virtual function, but it also prevents derived classes 
from overriding it.
*/