/*
std::any → type‑erased container.
    It can hold a value of any type without knowing the type at compile time, and you can safely retrieve it later.
    
    std::any_cast<T> → safely retrieves the stored value as type T.
        Throws std::bad_any_cast if the type doesn’t match.
    has_value() → checks if something is stored.
    reset() → clears the stored value.

    Useful for generic containers, plugin systems, or APIs where types vary.
    Safer than void* because it enforces type correctness at runtime.

    Diff between auto and std::any
    auto: 
        Compile‑time type deduction. Lets the compiler figure out the exact type of a variable.
        Type must be determinable at compile time.
        Strongly typed — once deduced, the type is fixed.
        No overhead — compiler knows the type.
    std::any:
        Runtime type erasure. Can hold any type, but the actual type is hidden until you cast it back.
        Type can vary at runtime; you don’t need to know it at compile time.
        Type‑safe, but requires std::any_cast<T> to retrieve the value. Wrong cast throws std::bad_any_cast.
        Slight runtime overhead due to type erasure and casting.
        use: Generic containers, plugin systems, or APIs where types vary dynamically.

    If you know the type at compile time → use auto.
    If the type can vary dynamically → use std::any.

    You don’t know the type at compile time — it could be anything.
    There’s no direct “which type is inside” API.
    Instead, you use:
        std::any_cast<T> → try to extract as type T.
        value.type() → returns a std::type_info object describing the stored type.

*/
#include <iostream>
#include <string>
#include <any>

using namespace std;

int main(){

    auto data = 10;
    cout<<"Data "<<data<<endl;
    //data = "Rajesh";   // Cant change type
    data = 10.5f;
    cout<<"Data "<<data<<endl;

    cout<<"start any example ---\n";
    // Create an empty std::any
    std::any value;
    value = 40;
    //std::cout<<value<<endl;
    std::cout<<std::any_cast<int>(value)<<endl;
    // Store a double
    value = 3.14;
    //std::cout<<std::any_cast<int>(value)<<endl;
    cout<<std::any_cast<double>(value)<<endl;
    value = std::string("Rajesh");
    cout<<std::any_cast<std::string>(value)<<endl;

    // Check if value has something
    if (value.has_value()) {
        std::cout << "Currently holds a value." << std::endl;
    }
    // Reset to empty
    value.reset();
    if (!value.has_value()) {
        std::cout << "Now empty." << std::endl;
    }

    // Wrong cast → throws std::bad_any_cast
    try {
        std::cout << std::any_cast<double>(value) << std::endl;
    } catch (const std::bad_any_cast& e) {
        std::cout << "Bad cast: " << e.what() << std::endl;
    }

    value = 42;

    // Inspect type at runtime
    std::cout << "Type: " << value.type().name() << std::endl;

    // Safe cast
    try {
        int x = std::any_cast<int>(value);
        std::cout << "It's an int: " << x << std::endl;
    } catch (const std::bad_any_cast& e) {
        std::cout << "Bad cast: " << e.what() << std::endl;
    }

    // Change type
    value = std::string("Rajesh");
    std::cout << "Type: " << value.type().name() << std::endl;

    return 0;
}
