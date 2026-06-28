#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> str = {"abc", "xyz", "abc", "hello"};

    std::replace(str.begin(), str.end(), std::string("abc"), std::string("$$$"));

    for (const auto& s : str) {
        std::cout << s << " ";
    }
}
