#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main() {
    std::vector<std::string> str = {"abc", "xyz", "hello", "abc"};

    // Replacement rules
    std::map<std::string, std::string> rules = {
        {"abc", "$$$"},
        {"xyz", "###"}
    };

    for (auto& s : str) {
        if (auto it = rules.find(s); it != rules.end()) {
            s = it->second; // replace with mapped value
        }
    }

    for (const auto& s : str) {
        std::cout << s << " ";
    }
}
