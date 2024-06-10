/*
#pragma GCC poison: This directive is supported by the GCC compiler and is used to remove an 
 identifier completely from the program. If we want to block an identifier then we can use the 
 #pragma GCC poison directive.
Example:

// Program to illustrate the 
// #pragma GCC poison directive
*/
  
#include <stdio.h>
  
#pragma GCC poison printf
  
int main()
{
    int a=10;
      
    if(a==10)
    {
        printf("GEEKSFORGEEKS");
    }
    else
        printf("bye");
  
    return 0;
}