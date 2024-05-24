#include <iostream>
#include <thread>
#include <chrono>

void listen_for_event(std::stop_token tk){
    while(1){
        std::cout<<"I am listening for any event!"<<std::endl;
        if(tk.stop_requested()){
            std::cout<<"Event generated!"<<std::endl;
            return;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(){
    std::jthread jth(listen_for_event);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    jth.request_stop();
    return 0;
}