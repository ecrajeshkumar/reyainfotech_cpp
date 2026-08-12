#include <iostream>
#include <cstring>

// memchr() in C is used to search for a character in a block of memory
// Returns a pointer to the first occurrence of value in the memory block.
// Returns NULL if the character is not found within the first num bytes.

using namespace std;

int main(){
    
    char str[] = "This is my book";
    char ch = 'm';
    int size = strlen(str);
    char* pos = (char*)memchr(str, ch, size);
    if(pos != NULL)
        cout<<*pos<<" :Character found"<<endl;
    else cout<<ch<<" :Character not found"<<endl;
    
    return 0;
}