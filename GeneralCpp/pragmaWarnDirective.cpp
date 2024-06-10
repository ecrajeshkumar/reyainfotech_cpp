/*
#pragma warn Directive: This directive is used to hide the warning messages which are displayed during compilation. This may be useful for us when we have a large program and we want to solve all the errors before looking on warnings then by using it we can focus on errors by hiding all warnings. we can again let the warnings be visible by making slight changes in syntax.
Syntax:

#pragma warn +xxx (To show the warning)
#pragma warn -xxx (To hide the warning)
#pragma warn .xxx (To toggle between hide and show)
We can hide the warnings as shown below:

#pragma warn -rvl: This directive hides those warning which are raised when a function which is supposed to return a value does not return a value.
#pragma warn -par: This directive hides those warning which are raised when a function does not uses the parameters passed to it.
#pragma warn -rch: This directive hides those warning which are raised when a code is unreachable. For example: any code written after the return statement in a function is unreachable.
Example:

// Example to explain the working of 
// #pragma warn directive
// This program is compatible with C/C++ compiler 
*/

#include<stdio.h>
  
#pragma warn -rvl /* return value */
#pragma warn -par /* parameter never used */
#pragma warn -rch /*unreachable code */
        
int show(int x)
{   
    // parameter x is never used in
    // the function
      
    printf("GEEKSFORGEEKS");
      
    // function does not have a
    // return statement
}
            
int main()
{
    show(10);
      
    return 0;
}