/*
    An enum (short for enumeration) in C++ is a user‑defined type that lets you assign names to a set of integral constants. 
    It’s useful when you want to represent a fixed group of related values (like colors, states, directions) with meaningful 
    names instead of raw numbers.

    enum = group of named integral constants.
    C++03 enums are unscoped and implicitly convert to int.
    C++11 enums (enum class) are scoped, strongly typed, and allow underlying type specification.

*/
==============================================================================================
enum Color { Red, Green, Blue };
Color c = Red;   // OK
int x = Green;   // implicit conversion to int

==============================================================================================
enum class Color { Red, Green, Blue };
Color c = Color::Red;   // must use scope
// int x = Color::Green; // ❌ error, no implicit conversion
int y = static_cast<int>(Color::Green); // ✅ explicit conversion

==============================================================================================
enum class ErrorCode : int;  // forward declaration

==============================================================================================
#include <iostream>
enum class Direction : char { North = 'N', South = 'S', East = 'E', West = 'W' };

int main() {
    Direction d = Direction::North;
    std::cout << static_cast<char>(d) << "\n"; // prints 'N'
}

==============================================================================================
enum Enum2 : unsigned int;       // Valid in C++11, the underlying type is specified explicitly.

// ✅ Valid in C++11
// Underlying type explicitly given, so forward declaration works.
enum class Enum3 : unsigned int; 

// ✅ Valid in C++11
// Scoped enum (enum class) defaults to int as underlying type.
enum class Enum4;   // Valid in C++11, the underlying type is int.

// ✅ Valid in C++11
// Scoped enum with explicit underlying type.
enum class Enum5 : unsigned int;

//enum Enum2 : unsigned short;     // Invalid in C++11, because Enum2 was formerly declared with a different underlying type.


int main() {
    return 0;
}