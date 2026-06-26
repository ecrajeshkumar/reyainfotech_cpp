#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

void printFrequency(string lstr){
    string s;
    map<string, int>mp;

    stringstream ss(lstr);
    while(ss >> s){
        mp[s]++;
    }
    for(auto &s : mp){
        cout<<s.first <<" "<<s.second<<"\n";
    }

}

int main(){
    string str = "Hi Geeks for Geeks Hi";
    printFrequency(str);
    return 0;
}