#include "extern_template_myheader.h"
#include <iostream>

void demo() {
    std::vector<int> v = {1, 2, 3};
    std::cout << "Size = " << v.size() << "\n";
}

int main() {
    demo();
    return 0;
}