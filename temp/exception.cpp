#include <iostream>
#include <exception>

using namespace std;
void myhandler()
{
    cout << "Inside new terminate handler\n";
    abort();
}

int main(){
    int x = -1;
    char* ptr;
  
    ptr = new char[256];
    
    set_terminate(myhandler);
    
    try {
  
        if (x < 0) {
            //throw x;
            throw 100;
        }
        if (ptr == NULL) {
            throw " ptr is NULL ";
        }
    }

    catch (char x) {
        cout << "Exception occurred: thrown value is " << x
             << endl;
    }
    catch(exception e){
        cout << "Exception occurred: exiting " <<e.what()<<endl;
    }
/*    catch(...){
        cout << "Unexcepted Exception occurred" << endl;
    }*/
    return 0;
}