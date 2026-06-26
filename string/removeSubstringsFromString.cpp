#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void eraseAllSubStr(string lstr, string temp){
    stringstream ss(lstr);
    string s, newstr;

    while(ss >> s){
        if (s.compare(temp) == 0){
            continue;
        }
        newstr.append(s);
        newstr.append(" ");
    }
    cout<<"Original string : \n"<<lstr;
    cout<<"\n After removing [this] string : \n"<<newstr;
}
int main()
{
    std::string str = "Hi this is a sample string is for is testing is.";
    eraseAllSubStr(str, "this");
    return 0;
}