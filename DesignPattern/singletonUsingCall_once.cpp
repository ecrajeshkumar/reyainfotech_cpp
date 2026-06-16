#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

using namespace std;

class Singleton{
    public:
        static Singleton& getInstance(){
            call_once(initFlag, [](){
                instance.reset(new Singleton);
            });
            return *instance;
        }

        void logAddress(int id){
            cout<<"Thread "<< id << " Singleton inistance address: "<< this <<"\n";  // std::cout itself is not thread‑safe. When multiple threads write to cout at the same time, their output can interleave or appear “random” because the writes are racing.
        }
    private:
        Singleton(){
            cout<<"Singleton initilized \n";
        }

        // Prevent copy/move
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton(Singleton&&) =  delete;
        Singleton& operator=(Singleton&&) = delete;

        static unique_ptr<Singleton> instance;
        static once_flag initFlag;
};

// static member definition
unique_ptr<Singleton>Singleton::instance;
once_flag Singleton::initFlag;

// Example usage
void worker(int id){
    Singleton::getInstance().logAddress(id);
}

int main(){
    constexpr int NUM_THREADS = 5;
    vector<thread>threads;

    for(int i = 0; i < NUM_THREADS; ++i){
        threads.emplace_back(worker, i);
    }
    for(auto& th: threads){
        th.join();
    }

    return 0;
}