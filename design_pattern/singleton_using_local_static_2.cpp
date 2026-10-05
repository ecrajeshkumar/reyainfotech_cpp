#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

class Logger{
    public:
        static Logger& getInstance(int n){
            static Logger log;
            cout<<"thread("<<n<<"):"<<this_thread::get_id()<<endl;
            return log; 
        }
        void getLogAddress(int n){
            cout<<"thread("<<n<<"):"<<this_thread::get_id()<<" instance_address_"<<this<<endl;
        }
    private:
        Logger(){
            cout<<"Logger()...\n";
        }
        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        Logger(Logger&&) = delete;
        Logger& operator=(Logger&&) = delete;
        //std::ofstream file; only for understanding
        //~Logger() = default;
        /*
            //~Logger() = default; which is harmless — it just makes explicit that you want the default destructor.
            Because we aren’t managing any dynamic resources (like new allocations, file handles, sockets), 
            the compiler‑generated destructor would work fine.
        */
        /*
            we’d only override destructor if your singleton manages resources that need cleanup at program termination, for example:
            Closing a file stream, Flushing logs to disk, Releasing a network connection, Freeing dynamically allocated memory. Otherwise a destructor is not needed.
        */
        /* // If a file object is needed/present in our code then implement a destructor.
        ~Logger() {
            std::cout << "Logger shutting down\n";
            file.close(); // explicit cleanup
        } */
        ~Logger() { std::cout << "Logger destroyed\n"; }
         /*
The C++ runtime guarantees that such objects are destroyed automatically at program exit.
Even if the destructor is private, the compiler has special access to call it because it’s part of the object’s lifetime management.
When you declare the destructor as private, it means user code cannot call delete on the singleton instance.
However, the compiler and runtime system are still allowed to call it when the program terminates.
         */
};

void worker(int i){
    //cout<<"thread_"<<i<<" running\n";
    Logger::getInstance(i).getLogAddress(i);
}


int main(){
    std::vector<thread> threads;
    constexpr int NUM_THREADS = 5;
    for(int i = 0; i < NUM_THREADS; ++i)
        threads.emplace_back(worker, i);
    for(auto&th:threads)
        th.join();
    // Logger&log = Logger::getInstance();
    // log.getLogAddress();
    // Logger&log2 = Logger::getInstance();
    // log2.getLogAddress();
    return 0;
}
