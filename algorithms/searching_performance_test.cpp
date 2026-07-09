/*
A performance comparison demo. We’ll test std::find(), std::binary_search(), and set::find() on large datasets to see how they scale.

std::find() is slow for large datasets because it checks every element.

std::binary_search() is extremely fast on sorted vectors due to logarithmic complexity.

set::find() is also logarithmic, but slightly slower than binary search because of tree overhead.

For unordered_set, .find() is even faster on average (O(1)).

👉 So in practice:

Use std::find() for small or unsorted containers.

Use std::binary_search() for sorted vectors/arrays when speed matters.

Use container .find() for associative containers (set, map, unordered_set, unordered_map).
*/


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    const int N = 1000000; // 1 million elements
    vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);

    set<int> s(v.begin(), v.end());

    int target = N - 1; // Worst-case search

    // Measure std::find()
    auto start = high_resolution_clock::now();
    auto it = find(v.begin(), v.end(), target);
    auto end = high_resolution_clock::now();
    cout << "std::find() time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    // Measure std::binary_search()
    start = high_resolution_clock::now();
    bool found = binary_search(v.begin(), v.end(), target);
    end = high_resolution_clock::now();
    cout << "std::binary_search() time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    // Measure set::find()
    start = high_resolution_clock::now();
    auto sit = s.find(target);
    end = high_resolution_clock::now();
    cout << "set::find() time: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";

    return 0;
}
