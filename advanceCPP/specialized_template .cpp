/*
 specialized template in C++ means you provide a custom implementation of a template for a specific type (or set of types). 
 It’s like saying: “Normally my template works generically, but if someone uses it with this particular type, 
 I want different behavior.
*/

// Generic template
template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Generic: " << value << "\n";
    }
};

// Full specialization for std::string
template <>
class Printer<std::string> {
public:
    void print(std::string value) {
        std::cout << "String specialization: " << value << "\n";
    }
};

int main() {
    Printer<int> p1; 
    p1.print(42);          // Generic version

    Printer<std::string> p2;
    p2.print("Rajesh");    // Specialized version
}
