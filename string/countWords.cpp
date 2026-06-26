#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void countWords(string lstr){
    stringstream ss(lstr);
    int count = 0;
    string s;

    while(ss >> s){
        ++count;
    }
    cout<<"Total number of words in this string : \n"<<lstr<<"\n"<<count<<"\n";
}


int main(){
    string str = "geeks for geeks geeks contribution placements";
    countWords(str);
    return 0;
}