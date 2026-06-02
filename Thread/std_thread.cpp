#include <iostream>
#include <thread>
using namespace std;

// A callable object
class myThread{
    public:
    void operator()(int num){
        for(int i = 0; i < num; ++i){
            cout<<"function object...: "<<(i+1)<<endl;
        }
    }
};

void fun(int num){
    for(int i = 0; i < num; ++i){
        cout<<"function pointer...: "<<(i+1)<<endl;
    }
}

int main(){
// This thread is launched by using function object as callable
    thread th1(myThread(),3);
// This thread is launched by using function pointer as callable
    thread th2(fun,3);
    auto fLambda = [](int num){
        for(int i = 0; i < num; ++i){
            cout<<"Lambda function...: "<<(i+1)<<endl;
        }
    };
    thread th3(fLambda,3);
    
    th1.join();
    th2.join();
    th3.join();
    
    return 0;
}