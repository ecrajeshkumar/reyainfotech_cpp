/*
Declared with &&.
Bind to temporary objects (rvalues) that would otherwise be destroyed.
int&& x = 10; // rvalue reference binds to temporary

Move Constructor:
Move constructors make STL containers efficient when handling temporaries or resizing.
Transfers ownership of resources instead of copying.
ClassName(ClassName&& other);

Copy constructor duplicates resources → expensive for large data.
Move constructor transfers ownership → efficient for temporaries.
Rvalue references (&&) enable move semantics.
STL containers (like vector, string) use move constructors internally for performance.

When vectors grow (e.g., during push_back or return from a function), they may need to reallocate memory. 
Without move constructors, this means copying every element. With move constructors, they can transfer ownership instead — 
much faster.

*/

#include <iostream>
#include <vector>
#include <string>

class MyData {
    std::string name;
public:
    // Constructor
    MyData(std::string n) : name(std::move(n)) {
        std::cout << "Constructed: " << name << "\n";
    }

    // Copy Constructor
    MyData(const MyData& other) : name(other.name) {
        std::cout << "Copied: " << name << "\n";
    }

    // Move Constructor
    MyData(MyData&& other) noexcept : name(std::move(other.name)) {
        std::cout << "Moved: " << name << "\n";
    }
};

int main() {
    std::vector<MyData> v;
    v.reserve(3); // reserve space to reduce reallocations

    std::cout << "--- Pushing elements ---\n";
    v.push_back(MyData("Alpha"));   // temporary → move
    v.push_back(MyData("Beta"));    // temporary → move
    v.push_back(MyData("Gamma"));   // temporary → move

    std::cout << "--- Returning vector from function ---\n";
    auto makeVector = []() {
        std::vector<MyData> temp;
        temp.push_back(MyData("Delta"));
        temp.push_back(MyData("Epsilon"));
        return temp; // move constructor used here
    };

    std::vector<MyData> v2 = makeVector();

    return 0;
}

/*
When pushing temporaries, the move constructor is used instead of copy.
When returning a vector from a function, the compiler uses Return Value Optimization (RVO) or move semantics.
This avoids expensive deep copies, especially for large objects.
STL containers like std::vector, std::string, and std::map all benefit from move semantics internally.
*/