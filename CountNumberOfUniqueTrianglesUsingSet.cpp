#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct myStruct{
    int a;
    int b;
    int c;
};
void mySort(int&a, int&b, int&c){
    vector<int>vect({a,b,c});
    sort(vect.begin(),vect.end());
    a = vect[0];
    b = vect[1];
    c = vect[2];
}

int main(){
    
    myStruct str[] = { {1,2,3}, {3,4,5}, {1,4,3}, {3,2,1},{5,4,3}};
    
    set<pair<int, pair<int,int>> >st;
    set<pair<int, pair<int,int>>> :: iterator it;
    
    size_t size = sizeof(str)/sizeof(str[0]);
    cout<<size<<endl;
/*    cout<<sizeof(str)<<endl;
     cout<<sizeof(str[0])<<endl;
*/
    
    for(int i = 0; i < size; ++i){
        int a = str[i].a, b = str[i].b, c = str[i].c;
        mySort(a,b,c);
        st.insert( { a, {b,c} }  );
    }
    cout<<st.size()<<endl;
    
    for(it = st.begin(); it != st.end(); it++){
      cout<< it->first << " " << it->second.first <<" "<<it->second.second<<endl;
    }
    
    
    return 0;
}