#include <iostream>
#include <cstring>

using namespace std;

int main(){
    
    char str[] = "This is my book";
    char ch = 'Y';
    int size = strlen(str);
    char* pos = (char*)memchr(str, ch, size);
    if(pos != NULL)
        cout<<ch<<" :Character found"<<endl;
    else cout<<ch<<" :Character not found"<<endl;
    
    return 0;
}