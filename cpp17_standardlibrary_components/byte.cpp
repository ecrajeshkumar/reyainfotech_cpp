// Program to illustrate std::byte
// in the C++ 17

#include <cstddef>
#include <iostream>

using namespace std;

// Function to print byte a
void Print(const byte& a) {
    cout << to_integer<int>(a) << endl;
}

// Driver Code
int main() {
    byte b{ 5 };

    // Print byte
    Print(b);

    // A 2-bit left shift
    b <<= 2;

    // Print byte
    Print(b);

    // Initialize two new bytes using
    // binary literals
    byte b1{ 0b1100 };
    byte b2{ 0b1010 };
    Print(b1);
    Print(b2);

    // Bit-wise OR and AND operations
    byte byteOr = b1 | b2;
    byte byteAnd = b1 & b2;

    // Print byte
    Print(byteOr);
    Print(byteAnd);

    return 0;
}