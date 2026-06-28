#include <iostream>
#include <tuple>

using namespace std;

pair<int,int>multipleValueReturn(int x, int y){
    return make_pair(x,y);
}

tuple<int, int, char> multipleReturn(int n1, int n2){
    return make_tuple(n2, n1, 'R');             
}

int main(){
    pair<int,int>retPair = multipleValueReturn(10,20);
    cout<<retPair.first<<" "<<retPair.second<<endl ;
    
    int a,b;
    char ch;
    tie(a, b, ch) = multipleReturn(100, 200);
    cout<<"a: "<<a<<" b: "<<b<<" ch: "<<ch<<endl;
    return 0;
}