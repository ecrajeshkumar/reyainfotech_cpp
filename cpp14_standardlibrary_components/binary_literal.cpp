
#include <iostream>
using namespace std;

int main() {
    // Binary literal (C++14 feature)
    int b = 0b1010;   // binary for decimal 10

    // Digit separator (C++14 feature)
    int n = 1'000'000; // one million, easier to read

    cout << "Binary literal 0b1010 = " << b << endl;
    cout << "Digit separator 1'000'000 = " << n << endl;

    return 0;
}
