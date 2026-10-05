#include <iostream>
#include <tuple>

using namespace std;
/*
    It group together multiple values of potentially different types into a single object.
*/
pair<int,int>multipleValueReturn(int x, int y){
    return make_pair(x,y);
}
template<typename T1, typename T2>
tuple<T1, T2, char> multipleReturn(T1 n1, T2 n2){
    return make_tuple(n1, n2, 'R');             
}

template<typename T1, typename T2, typename T3>
tuple<T1, T2, T3> multipleReturn(T1 n1, T2 n2, T3 n3){
    return make_tuple(n1, n2, 'K');             
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