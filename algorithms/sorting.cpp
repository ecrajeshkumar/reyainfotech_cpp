/*
Sorting in STL depends on container type, dataset size, and conditions. 
std::sort()
    Works with random-access iterators (vector, deque, array).
    Complexity:
        Average/Worst: 𝑂(𝑛log⁡𝑛)
        Best (nearly sorted): 𝑂(𝑛)
    Use case: Best for large datasets in vectors/arrays.
list::sort() Member function of std::list.
    Uses merge sort internally.
        Complexity: 𝑂(𝑛log⁡𝑛)

Ordered containers (set, map) :
    Already sorted by key internally using balanced BST (Red-Black Tree). No need to sort manually.
    Complexity of insertion/search: 𝑂(log𝑛)
Unordered containers (unordered_set, unordered_map)
    Based on hash tables.
    No sorting possible (unordered by design).

For small datasets: std::sort() is usually fastest (insertion sort kicks in internally).
For large datasets: std::sort() still scales well; use std::stable_sort() if you need stable ordering.
For linked lists: Always use list::sort().
For maps/sets: Sorting

Small datasets: Differences are negligible; both std::sort and list::sort are fine.
Large datasets: std::sort on vector is significantly faster than list::sort because random-access memory access is cache-friendly.
Stable sorting: Use std::stable_sort when you need to preserve relative order of equal elements, but expect extra overhead.
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

template <typename Func>
void measure_time(const string& label, Func f) {
    auto start = high_resolution_clock::now();
    f();
    auto end = high_resolution_clock::now();
    cout << label << " took "
         << duration_cast<milliseconds>(end - start).count()
         << " ms\n";
}

int main() {
    const int SMALL = 1000;
    const int LARGE = 1000000;

    // Vector (random-access)
    vector<int> v_small(SMALL), v_large(LARGE);
    for (int i = 0; i < SMALL; i++) v_small[i] = SMALL - i;
    for (int i = 0; i < LARGE; i++) v_large[i] = LARGE - i;

    // List (linked list)
    list<int> l_small(v_small.begin(), v_small.end());
    list<int> l_large(v_large.begin(), v_large.end());

    // --- Sorting small dataset ---
    measure_time("std::sort on vector (small)", [&]() {
        sort(v_small.begin(), v_small.end());
    });

    measure_time("list::sort on list (small)", [&]() {
        l_small.sort();
    });

    // --- Sorting large dataset ---
    measure_time("std::sort on vector (large)", [&]() {
        sort(v_large.begin(), v_large.end());
    });

    measure_time("list::sort on list (large)", [&]() {
        l_large.sort();
    });

    // --- Stable sort example ---
    measure_time("std::stable_sort on vector (large)", [&]() {
        stable_sort(v_large.begin(), v_large.end());
    });

    return 0;
}

