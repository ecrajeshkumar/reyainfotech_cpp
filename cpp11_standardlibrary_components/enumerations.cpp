/*
Always specify an underlying type if you plan to forward-declare enums.
Use enum class for type safety and to avoid name clashes.
Be consistent: once you declare an enum with a type, stick with it.
*/

// ❌ Invalid in C++03 and C++11
// No underlying type specified, so compiler cannot know how big Enum1 is.
// enum Enum1;  // Invalid in C++03 and C++11; the underlying type cannot be determined.

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