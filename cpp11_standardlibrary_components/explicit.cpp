/*
the explicit keyword is used to prevent unintended implicit conversions when a constructor or conversion operator can be called 
with a single argument. It enforces that such calls must be made explicitly, improving type safety.

Without explicit, a constructor taking a single argument can be used for implicit conversions, sometimes leading to subtle bugs.
With explicit, the compiler requires you to write the conversion clearly.

*/

#include <iostream>
#include <string>

using namespace std;

class MyClass {
    int value;
public:
    explicit MyClass(int v) : value(v) {}  // explicit constructor

    void show() const {
        std::cout << "Value = " << value << "\n";
    }
};

int main() {
    //MyClass obj1 = 10; 
    // Above statement is going to implicit conversion which is not correct to convert as implicity 
    // so not allowed/write  so constructor declare as explicit then this statemnet give eoor.
    // ❌ ERROR: implicit conversion not allowed when declare constructor as explicit.
    MyClass obj1(10);   // ✅ OK: explicit call
    
    obj1.show();
    /*
        explicit MyClass(int v) prevents MyClass obj2 = 20; from compiling.
        You must write MyClass obj2(20); instead.
    */
}