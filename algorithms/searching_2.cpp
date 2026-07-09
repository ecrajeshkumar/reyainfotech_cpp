/*

std::find() → Works everywhere, but always O(n).

std::binary_search() → Only for sorted, random-access containers like vector, deque, array. Complexity O(log n).

Container .find() → Optimized for associative containers (set, map, unordered_set, unordered_map).

    Ordered containers: O(log n)

    Unordered containers: O(1) average

*/


#include <iostream>
#include <vector>
#include <algorithm>   // for std::find, std::binary_search
#include <set>         // for std::set

int main() {
    // Example 1: std::find() on vector
    std::vector<int> v = {10, 20, 30, 40, 50};
    auto it = std::find(v.begin(), v.end(), 30);
    if (it != v.end())
        std::cout << "std::find: Found at index " << (it - v.begin()) << "\n";
    else
        std::cout << "std::find: Not found\n";

    // Example 2: std::binary_search() on sorted vector
    std::vector<int> sorted_v = {10, 20, 30, 40, 50};
    if (std::binary_search(sorted_v.begin(), sorted_v.end(), 40))
        std::cout << "std::binary_search: Found 40\n";
    else
        std::cout << "std::binary_search: Not found\n";

    // Example 3: set::find() on std::set
    std::set<int> s = {10, 20, 30, 40, 50};
    auto sit = s.find(20);
    if (sit != s.end())
        std::cout << "set::find: Found " << *sit << "\n";
    else
        std::cout << "set::find: Not found\n";

    return 0;
}
