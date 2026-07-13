/*
static_assert to catch errors early at compile time.
static_assert is a compile‑time assertion mechanism. It lets you check conditions during compilation, 
and if the condition is false, the compiler emits an error with a custom message. This is extremely 
useful for enforcing type traits, template constraints, or invariants that must hold before the program even runs.

static_assert(condition, "error message");
    condition → must be a constant expression (evaluated at compile time).
    error message → string literal shown if the assertion fails.
*/
#include <iostream>
#include <string>

using namespace std;

template <int N>
struct Array {
    static_assert(N > 0, "Array size must be positive");
    int data[N];
};

template <typename T>
struct OnlyIntegral {
    static_assert(std::is_integral<T>::value, "T must be an integral type");
};


int main() {
    Array<5> a;   // ✅ compiles
    //Array<0> b;   // ❌ compile-time error

    OnlyIntegral<int> ok;     // ✅ compiles
    OnlyIntegral<double> bad; // ❌ compile-time error: "T must be an integral type"


    return 0;
}