#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
#include<algorithm>

using namespace std;

void worker(int id){
    cout<<"I am worker thread_"<<id<<endl;
}

int main(){

//removed below { then judge op    
{
    std::vector<jthread> workers;
    for(int i = 0; i < 5; ++i){
        workers.emplace_back(jthread(worker,i));
    }
}   
    // std::for_each(workers.begin(), workers.end(), [](std::jthread &th){
    //     assert(th.joinable());
    //     th.join();
    // });
    
    cout<<"Ending main now..."<<endl;
    return 0;
}