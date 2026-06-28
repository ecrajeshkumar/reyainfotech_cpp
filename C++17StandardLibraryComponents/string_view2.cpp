/*
    processString(const std::string&) → even though it takes by reference, creating a std::string from a literal or substring often involves allocation/copy.
    processStringView(std::string_view) → no allocation, just a pointer + length.
    
    std::string → slower, because it may involve construction/copy overhead.
    std::string_view → faster, because it avoids copies and works directly on existing memory.

    Use std::string when you need ownership or modification of the data.
    Use std::string when you need ownership or modification of the data.

*/

#include <iostream>
#include <string>
#include <string_view>
#include <chrono>

constexpr int count = 1000000; // 1 million iterations

// Function using std::string (copies data)
void processString(std::string str){
    volatile auto len = str.size(); // prevent optimization
    //std::cout << "string len: "<< len << std::endl;
}
// Function using std::string_view (no copy)
void processString_view(std::string_view strv){
    volatile auto len = strv.size(); // prevent optimization
    //std::cout << "string_view len: "<< len << std::endl;
}

int main(){

    std::string text = "I am your boss !!!";

    // Benchmark std::string
    auto start1 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < count; ++i)
        processString(text);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "std::string time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count()
              << " ms\n";
    
    auto start2 = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < count; ++i)
        processString_view(text);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "std::string_view time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count()
              << " ms\n";
    return 0;
}