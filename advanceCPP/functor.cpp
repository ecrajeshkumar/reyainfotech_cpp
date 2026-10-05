/*
    A functor in C++ is simply an object that can be called like a function. 
    Technically, it’s any class or struct that overloads the operator().

    A functor is an object with operator() that acts like a function but can hold state. 
    They’re powerful for callbacks, predicates, and algorithms. In modern C++, lambdas are the most common way to create functors 
    quickly.

    Function: Just code, no memory of past values.
    Functor: Object with operator(), can carry extra data/state.
*/


#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct IsEven {
    bool operator()(int x) const { return x % 2 == 0; }
};

struct Adder {
    int offset;
    Adder(int o) : offset(o) {
        cout<<"Constructor\n";
    }
    int operator()(int x) const {
        cout<<"functor\n";
        return x + offset;
    }
};

int main() {
    vector<int> nums = {1,2,3,4,5,6};
    auto it = find_if(nums.begin(), nums.end(), IsEven());
    cout << *it; // prints 2
    
    cout<<"======================\n";
    
    Adder add5(5);       // functor with state
    cout << add5(10);    // prints 15
}
// Here, IsEven is a functor used as a predicate in std::find_if.
