/*
std::variant → type‑safe union.
    std::variant<Ts...> → can hold one of several types safely.
    std::visit → applies a callable to the currently held value.
    std::holds_alternative<T>(variant) → checks if the variant currently holds type T.
    Type safety → unlike union, std::variant ensures only one valid type is active and prevents unsafe access.

    Diff between union and variant:
    Union: 
        Only one member can be initialized at a time. No automatic constructors/destructors.
        Direct member access (u.i, u.f). Programmer must know which is valid.
        Undefined behavior if wrong member accessed.
    std::variant:
        Properly constructs and destructs the active type.
        Use std::get<T>(variant) or std::visit to safely access the active type.
        Throws std::bad_variant_access if you try to get the wrong type.

    You know the set of possible types at compile time.
    You can check with std::holds_alternative<T>(var) or use std::visit.
*/

#include <iostream>
#include <variant>
#include <string>

union MyUnion {
    int i;
    float f;
};

void printVariant(std::variant<int, float, std::string>&var){
    // Use std::visit to handle all possible types
    std::visit([](auto&& arg){
        std::cout << "Value: " << arg << std::endl;
    },var);
}


int main() {
    
    // Union
    MyUnion u;
    u.i = 42;
    std::cout << u.i << std::endl;

    u.f = 3.14f;
    std::cout << u.f << std::endl;

    // Accessing u.i now is undefined behavior!
    std::cout << u.i << std::endl;

    ////////////////////// std::Variant //////////////////////////////////////////
    
    std::variant<int, float, std::string> v;

    v = 42;
    std::cout << std::get<int>(v) << std::endl;

    v = 3.14f;
    std::cout << std::get<float>(v) << std::endl;

    v = std::string("Rajesh");
    std::cout << std::get<std::string>(v) << std::endl;

    // Safe check
    if (std::holds_alternative<int>(v)) {
        std::cout << "Currently holds int" << std::endl;
        std::cout << std::get<int>(v) << std::endl;
    }else if (std::holds_alternative<std::string>(v)) {
        std::cout << "Currently holds string" << std::endl;
        std::cout << std::get<std::string>(v) << std::endl;
    }else if(std::holds_alternative<float>(v)){
        std::cout << "Currently holds float" << std::endl;
        std::cout << std::get<float>(v) << std::endl;
    }
    v = 100;
    if (std::holds_alternative<int>(v)) {
        std::cout << "Currently holds int" << std::endl;
        std::cout << std::get<int>(v) << std::endl;
    }else if (std::holds_alternative<std::string>(v)) {
        std::cout << "Currently holds string" << std::endl;
        std::cout << std::get<std::string>(v) << std::endl;
    }else if(std::holds_alternative<float>(v)){
        std::cout << "Currently holds float" << std::endl;
        std::cout << std::get<float>(v) << std::endl;
    }
    printVariant(v);
    // A variant that can hold int, double, or string
    //std::variant<int, double, std::string> var(100, 10.5, "Rajesh");
    // A std::variant can only hold one active type at a time. The constructor must match exactly one of the alternative types.
    // std::variant<int, double, std::string> var(100); // holds int
    // std::variant<int, double, std::string> var(10.5); // holds double
    // std::variant<int, double, std::string> var("Rajesh"); // holds string
    /*
        std::variant is a type‑safe union → only one type is active at a time.
        You can assign different types sequentially, but not all at once.
        If you need to store multiple values simultaneously, use a std::tuple instead:
    */

    return 0;
}


