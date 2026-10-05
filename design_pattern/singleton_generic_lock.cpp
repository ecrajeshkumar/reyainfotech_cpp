#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

class Logger{
    public:
        
        static Logger* getInstance(int n){
            if(instance == nullptr){
                lock_guard<mutex>lck(mut);
                if(instance == nullptr){
                    instance = new Logger();
                    cout<<"thread("<<n<<"):"<<this_thread::get_id()<<endl;
                }
            }
            return instance;
        }
        void getLogAddress(int n){
            cout<<"thread("<<n<<"):"<<this_thread::get_id()<<" instance_address_"<<this<<endl;
        }
        static void destroyInstance() {
            delete instance;
    	    instance = nullptr;
        }
    
    private:
        static Logger* instance;
        Logger(){
            cout<<"Logger()..."<<endl;
        }
        static mutex mut;
       ~Logger() { std::cout << "Logger destroyed\n"; }
        /*
	Because we used new, the destructor (~Logger) will not be called automatically at program exit.
    Static pointers themselves are cleaned up, but the object they point to remains allocated until you explicitly delete it.
    So in this current code, the destructor is never invoked → memory leak.

        */
        Logger(const Logger&) = delete;
        Logger&operator=(const Logger&) = delete;
        Logger(Logger&&) = delete;
        Logger&operator=(Logger&&) = delete;
};

Logger* Logger::instance = nullptr;
mutex Logger::mut;
void worker(int i){
    Logger::getInstance(i)->getLogAddress(i);
}

int main(){
    vector<thread>threads;
    constexpr int MAX_THREAD = 5;
    for(int i = 0; i < MAX_THREAD; ++i)
        threads.emplace_back(worker, i);
    for(auto&th:threads)
        th.join();
   Logger::destroyInstance();
    return 0;
}


// Logger()...
// thread(0):124470269974208
// thread(0):124470269974208 instance_address_0x713478000b70
// thread(3):124470244796096 instance_address_0x713478000b70
// thread(1):124470261581504 instance_address_0x713478000b70
// thread(4):124470165501632 instance_address_0x713478000b70
// thread(2):124470253188800 instance_address_0x713478000b70
// Logger destroyed
