#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
#include<algorithm>

using namespace std;

void work(){
    cout<<"I am worker thread and my id is: "<<std::this_thread::get_id()<<endl;
}

int main(){
    
    std::vector<thread> workers;
    
    for(int i = 0; i < 5; ++i){
        workers.emplace_back(thread(work));
        std::this_thread::sleep_for(std::chrono::seconds(1));
        cout<<"Created here and it's ID : "<<workers[i].get_id()<<endl;
    }
    std::for_each(workers.begin(), workers.end(), [](std::thread &th){
        assert(th.joinable());
        th.join();
    });
    
    return 0;
}