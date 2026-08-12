#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool checkBracketsBalanced(string str){
    stack<char>stk;
    char ch;
    
    for(int i = 0; str[i] != '\0'; ++i){
        if(str[i] == '(' || str[i] == '{' || str[i] == '['){
            stk.push(str[i]);
            continue;
        }
        switch(str[i]){
            case ')' :
                ch = stk.top();
                stk.pop();
                if(ch != '(')
                    return false;
                break;
            case '}' :
                ch = stk.top();
                stk.pop();
                if(ch != '{')
                    return false;
                break;
            case ']' :
                ch = stk.top();
                stk.pop();
                if(ch != '[')
                    return false;
                break;
        }
    }
    return (stk.empty());
}


int main(){
    
    string expr("[{}(]");
    if(checkBracketsBalanced(expr))
        cout<<"Balanced !!!";
    else
        cout<<"Not Balanced !!!";
    return 0;
}