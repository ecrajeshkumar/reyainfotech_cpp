/*
    Linear search is the simplest search algorithm: it checks each element in a list sequentially until the target is found or the list ends. 
    Its time complexity is 𝑂(𝑛) in the worst and average cases, and 𝑂(1) in the best case.
    Best    O(1) Target is at the first index.
|   Worst   O(n) Target is at the last index or not present.

    Use case of linear search: Works on both sorted and unsorted data.
        Output: Returns the index of the target element if found, otherwise returns -1.
        Applications:
            Searching in unsorted lists
            Useful for small datasets but Inefficient for large datasets compared to algorithms like binary search.
            In short: Linear search is best for small or unsorted collections, but for large datasets, more efficient algorithms like binary search should be used.
    
    std::find() :
    std::find() is a generic algorithm in <algorithm> that works with any STL container (like vector, list, deque, array, set, map, etc.) as long as the container 
    provides iterators. It performs a linear search between two iterators (first and last). 

    std::binary_search() :
    It requires random-access iterators (like those from vector, deque, array). only for sorted containers. It returns true if the element is found, otherwise false.
    Time complexity:
    O(log n) for random-access containers.
    Cannot be used with containers like list, set, or map because they don’t provide random-access iterators.

    Use container-specific .find() for associative containers like set or map.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
int linearSearch(vector<int>& arr, int x) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == x) return i; // Found
    }
    return -1; // Not found
}

int main() {
    vector<int> arr = {2, 3, 4, 10, 40};
    int x = 10;
    int result = linearSearch(arr, x);
    if (result == -1)
        cout << "Element not present";
    else
        cout << "Element found at index " << result;
    return 0;
}

*/
int main() {
    vector<int> vec = {2, 4, 6, 6, 8, 10};
    int key = 6;

    // Linear search (works on unsorted too)
    bool found = (find(vec.begin(), vec.end(), key) != vec.end());
    cout << "Found (linear): " << found << "\n";

    // Binary search (requires sorted)
    bool binaryFound = binary_search(vec.begin(), vec.end(), key);
    cout << "Found (binary): " << binaryFound << "\n";

    // lower_bound: first position not less than key (i.e. first ≥ key)
    int firstIndex = lower_bound(vec.begin(), vec.end(), key) - vec.begin();
    cout << "First ≥ key at index: " << firstIndex << "\n";

    // upper_bound: first position greater than key
    int afterIndex = upper_bound(vec.begin(), vec.end(), key) - vec.begin();
    cout << "First > key at index: " << afterIndex << "\n";

    return 0;
}