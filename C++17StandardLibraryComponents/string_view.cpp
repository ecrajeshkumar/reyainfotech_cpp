/*'
std::string_view → lightweight string reference.
    It does not allocate or copy memory — just points to existing characters.
    Useful for read-only access to strings, especially substrings.
    Safer and faster than passing const std::string& when dealing with literals or slices.
    It’s especially powerful in APIs where you want flexibility (accept literals, std::string, or slices) without extra copies.
        Example: void log(std::string_view msg);
*/
#include <iostream>
#include <string>
#include <string_view>

void printName(std::string_view name){
    std::cout << "Name: " << name << std::endl;
}

#include <iostream>


int main(){

    std::string str = "Rajesh";
    // Pass std::string directly
    printName(str);
    // Pass string literal directly (no std::string needed)
    printName("Hello World");
    std::string_view s = "kumar";
    printName(s);
    std::string_view ss("Rakesh kumar");
    printName(ss);

    // Create a substring view (no allocation, no copy)
    std::string_view sub(str.c_str(), 3);
    std::cout<<"Substring view: "<<sub<<std::endl;

    return 0;
}