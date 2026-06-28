/*
    Whether new(pair) is not present in the dictionary or it is already present. If the new(pair) association (key-value pair) is not 
    present in the dictionary, and it gets inserted. So in this case, the returned pair contains an iterator pointing to the new 
    element and the boolean value becomes True.
    If the new key is already present then the iterator points to the existing key and boolean value becomes False.
    Now to write the code to inspect the boolean flag and insertion iterator, first write .first and .second to access elements 
    in pair. C++ 17 can do better for this as:

    Using C++ 17 structure bindings to declare and initialize two variables with more meaningful names than first and second.
    Using the names position and success is much clearer than using first and second.
    The meaning of position and success is very straightforward i.e., position tells about where the iterator is and success tells 
    whether the element is inserted or not.
*/

// C++ 17 program to demonstrate 
// Structure Bindings 
  
#include <iostream> 
#include <map> 
#include <string> 
using namespace std; 
  
// Driver Code 
int main() 
{ 
    // Key-value pair declared inside 
    // Map data structure 
    map<string, string> fav_lang{ 
        { "John", "Java" }, 
        { "Alex", "C++" }, 
        { "Peter", "Python" } 
    }; 
  
    // Structure binding concept used 
    // position and success are used 
    // in place of first and second 
    auto[process, success] 
        = fav_lang.insert({ "Henry", 
                            "Golang" }); 
  
    // Check boolean value of success 
    if (success) { 
        cout << "Insertion done!!"
             << endl; 
    } 
  
    // Iterate over map 
    for (const auto & [ name, lang ] : fav_lang) {
        cout << name << ":"
             << lang << endl; 
    } 
    return 0; 
}