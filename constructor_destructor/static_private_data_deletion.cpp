#include <iostream>
class A {
private:
    static int* data;
public:
    A() {
        if (!data) {
            data = new int[10];
            std::cout << "Allocated once\n";
        }
    }
    ~A() {
        // Do NOT delete here, because multiple objects share it.
        // Provide a static cleanup method instead.
    }
    static void cleanup() {
        delete[] data;
        data = nullptr;
        std::cout << "Freed\n";
    }
};
int* A::data = nullptr;

int main() {
    A* ptr = new A();
    delete ptr;
    A::cleanup();  // free shared memory explicitly
    return 0;
}
