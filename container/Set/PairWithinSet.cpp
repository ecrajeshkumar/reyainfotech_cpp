#include <iostream>
#include <set>
using namespace std;

int main(){
    
    set<pair<int,int>>st;
    st.insert({1 , 2});
    st.insert({3 , 4});
    st.insert({1 , 2});
    st.insert({3 , 5});
    st.insert({4 , 5});
    cout<<"Size of set_1: "<<st.size()<<endl;
    set<pair<int , int>> :: iterator it;
    for(it = st.begin(); it != st.end(); it++){
      cout<< it->first << " " << it->second <<endl;
    }
    return 0;
}