/*
std::initializer_list<T> makes initialization cleaner and safer, especially for containers and constructors.
*/

#include <iostream>
#include <initializer_list>
#include <vector>

class MyVector {
    std::vector<int> data;
public:
    // Constructor accepts initializer_list
    MyVector(std::initializer_list<int> list) {
        for (auto val : list) {
            data.push_back(val);
        }
    }

    void print() const {
        for (auto val : data) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

void printList(std::initializer_list<int> list) {
    for (auto val : list) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}

int main() {
    MyVector v = {1, 2, 3, 4, 5}; // calls initializer_list constructor

    printList({10, 20, 30, 40}); // pass a brace-enclosed list
    
    v.print();


    return 0;
}
