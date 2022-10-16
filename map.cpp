#include <iostream>
#include <map>
#include <algorithm>


using namespace std;

int main(){
    
    map<int, int> myMap;
    myMap.insert(pair<int, int>(1,10));
    myMap[2] = 20;
    myMap[2] = 30;
    myMap[3] = 40;
    myMap[4] = 40;
    
    int key = 2;
    auto ret = myMap.find(key);
    if(ret == myMap.end()) cout<<"Not present..."<<endl;
    else cout<<"Present..."<<endl;
    
    map<int,int>::iterator itr;
    for(itr = myMap.begin(); itr != myMap.end(); ++itr){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    
    cout<<"End..................."<<endl;
    map<pair<int,int>,int>myMap2;
    myMap2.insert(make_pair(make_pair(0,0),0));
    myMap2.insert(make_pair(make_pair(0,1),1));
    myMap2.insert(make_pair(make_pair(1,0),1));
    myMap2.insert(make_pair(make_pair(1,1),1));
    myMap2[{0,0}] = 10;
    myMap2[{2,0}] = 0;
    myMap2[{3,1}] = 1;
    myMap2[{4,0}] = 1;
    myMap2[{5,1}] = 1;
    map<pair<int,int>,int>::iterator itr2;
    for(itr2 = myMap2.begin(); itr2 != myMap2.end(); ++itr2){
        cout<<itr2->first.first<<" ";
        cout<<itr2->first.second<<" ";
        cout<<itr2->second<<endl;
    }
    
    
    
    
    
    
    
    
    return 0;
}