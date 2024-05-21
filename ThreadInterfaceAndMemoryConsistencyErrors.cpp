#include <iostream>
#include <thread>

using namespace std;
  
class thread_obj {
public:
   
 void operator()(int x)
 {
    for (int i = 1; i < 11; i++)
    {
      cout << "Thread " << x << "\n";
    }
 }
};
  
// Driver code
int main()
{
   // thread 1
   thread th1(thread_obj(), 1);
  
   // thread 2
   thread th2(thread_obj(), 2);
  
   // wait for thread1 to join
   th1.join();
  
   // wait for thread2 to join
   th2.join();
    
   return 0;
}