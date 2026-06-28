#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mut;
condition_variable cv;
int count = 0;

class OddNumber{
    public:
        
        void printOdd(){
            while( count != 10){
                unique_lock<mutex>lock(mut);
                cv.wait(lock, [](){ return count%2 != 0;} );
                cout<<"OddNumber: "<<count<<endl;
                count++;
                cv.notify_all();
                mut.unlock();
            }
        }
};
class EvenNumber{
    public:
         void printEven(){
            while(count != 10){
                unique_lock<mutex>lock(mut);
                cv.wait(lock, [](){ return count%2 == 0;} );
                cout<<"EvenNumber: "<<count<<endl;
                count++;
                cv.notify_all();
                mut.unlock();
            }
        }
};

int main()
{
    OddNumber odd;
    EvenNumber even;
    thread oddTh(&OddNumber::printOdd, odd);
    thread evenTh(&EvenNumber::printEven, even);
    oddTh.join();
    evenTh.join();
    //while(count != 10);
    cout<<"Ending..."<<endl;
    return 0;
}