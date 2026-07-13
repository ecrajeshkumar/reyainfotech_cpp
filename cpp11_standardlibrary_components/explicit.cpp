/*
the explicit keyword is used to prevent unintended implicit conversions when a constructor or conversion operator can be called 
with a single argument. It enforces that such calls must be made explicitly, improving type safety.
एक्सप्लिसिट कीवर्ड का उपयोग तब अनपेक्षित अप्रत्यक्ष रूपांतरणों को रोकने के लिए किया जाता है जब किसी कंस्ट्रक्टर या रूपांतरण ऑपरेटर को एकल तर्क के साथ कॉल 
किया जा सकता है। यह सुनिश्चित करता है कि ऐसे कॉल स्पष्ट रूप से किए जाने चाहिए, जिससे टाइप सुरक्षा में सुधार होता है।

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
    MyClass obj1(10);   // ✅ OK: explicit call
    //MyClass obj1 = 10; // ❌ ERROR: implicit conversion not allowed
    obj1.show();
    /*
        explicit MyClass(int v) prevents MyClass obj2 = 20; from compiling.
        You must write MyClass obj2(20); instead.
    */
}