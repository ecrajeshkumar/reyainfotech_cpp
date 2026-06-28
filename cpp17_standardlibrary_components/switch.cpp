/*

*/

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::string> items = {"abc", "xyz", "hello"};

    // Declare variable inside switch
    switch (auto it = std::find(items.begin(), items.end(), "xyz"); it != items.end()) {
        case true:  // found
            *it = "###";
            std::cout << "Replaced xyz with ###\n";
            break;
        case false: // not found
            std::cout << "String not found\n";
            break;
    }
}

