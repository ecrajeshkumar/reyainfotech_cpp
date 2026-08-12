/*

std::set stores elements in sorted order using a balanced tree (Red-Black Tree), while std::unordered_set stores elements in arbitrary order using a hash table. This means set guarantees order but has slower operations (O(log n)), whereas unordered_set is faster on average (O(1)) but does not preserve order.
			
							set														unordered_set
Ordering : 					Elements always sorted (ascending by default)			No ordering guaranteed
Underlying structure :		Self-balancing Red-Black Tree							Hash table
Insertion/Deletion/Lookup	O(log n)												average O(1), worst-case O(n) (collisions)
Duplicates					Not allowed												Not allowed	
Iteration					Traverses in sorted order								Traverses in arbitrary order
Use cases					When sorted order is required, or range queries are needed	When speed matters and order doesn’t
preserve order				No														No
*/

#include <iostream>
#include <vector>
#include <unordered_set>

int main() {
    std::vector<int> vec = {1, 6, 2, 3, 5, 3, 4};
    std::unordered_set<int> seen;
    std::vector<int> result;

    for (int v : vec) {
        if (seen.insert(v).second) {   // true if v was not already in set
            result.push_back(v);       // keep first occurrence
        }
    }

    for (int x : result) {
        std::cout << x << " ";
    }
}
