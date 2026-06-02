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
    unsigned long int hardware_thread = thread::hardware_concurrency();
    cout<<"No of thread supporting by our machine is "<<hardware_thread<<endl;
    for(int i = 0; i < hardware_thread; ++i){
        //thread th = thread(worker, i);
        workers.emplace_back(thread(worker, i));
    }
    
    for_each(workers.begin(), workers.end(), [](thread &th){
        assert(th.joinable());
        th.join();
    });
   
    return 0;
}