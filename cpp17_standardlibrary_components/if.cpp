/*

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> str = {"abc", "xyz", "hello", "abc"};

    // Replace "abc" with "$$$"
    if (auto it = std::find(str.begin(), str.end(), "abc"); it != str.end()) {
        *it = "$$$";
    }

    // Replace "xyz" with "###"
    if (auto it = std::find(str.begin(), str.end(), "xyz"); it != str.end()) {
        *it = "###";
    }

    // Print result
    for (const auto& s : str) {
        std::cout << s << " ";
    }

    std::cout<<"\n";

/*
Befre c++17
*/

    std::vector<std::string> str2 = {"abc", "xyz", "hello", "abc"};
    // Find and replace abc with $$$
    const auto it = find(begin(str2), end(str2), "abc");

    if (it != end(str2)) {
       *it = "$$$";
    }

    const auto it2 = find(begin(str2), end(str2), "xyz");

    if (it2 != end(str2)) {
       *it2 = "###";
    }

    // Print result
    for (const auto& s : str2) {
        std::cout << s << " ";
    }

    return 0;
}


