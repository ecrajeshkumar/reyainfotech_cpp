#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

void worker(int num){
    cout<<"Worker Thread "<<num<<" running..."<<endl;
}

int main(){
    vector<thread>workers;
    for(int i = 0; i < 10; ++i){
        thread th = thread(worker, i);
        workers.push_back(move(th));
    }
    
    for_each(workers.begin(), workers.end(), [](thread &th){
        assert(th.joinable());
        th.join();
    });
   
    return 0;
}