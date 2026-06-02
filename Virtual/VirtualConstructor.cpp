/*
 *  If we make a constructor virtual, the compiler flags an error. 
 * In fact, except inline, no other keyword is allowed in the declaration of the constructor.
 * object creation and object type are tightly coupled which forces modifications to extended. 
 * The objective of the virtual constructor is to decouple object creation from its type.
*/
#include <iostream>
using namespace std;
 
//// LIBRARY START
class Base{
public:
    Base() { cout<<"Base..."<<endl;}
    virtual ~Base() { cout<<"~Base..."<<endl;}
    virtual void DisplayAction() = 0;
};
 
class Derived1 : public Base {
public:
    Derived1(){ cout<<"Derived1..."<<endl;}
    ~Derived1(){ cout<<"~Derived1..."<<endl;}
    void DisplayAction(){
        cout << "Action from Derived1" << endl;
    }
};
 
class Derived2 : public Base {
public:
    Derived2() {cout<<"Derived2..."<<endl; }
    ~Derived2(){cout<<"~Derived2..."<<endl; }
    void DisplayAction(){
        cout << "Action from Derived2" << endl;
    }
};
 
//// LIBRARY END
 
class User
{
public:
 
    // Creates Derived1 or Derived2 based on input
    User(Base* base = nullptr) : pBase(base) {
        cout<<"User..."<<endl;
    }
    
    ~User(){
        cout<<"~User..."<<endl;
        if( pBase ){
            delete pBase;
            pBase = nullptr;
        }
    }
 
    // Delegates to actual object
    void Action()
    {
        pBase->DisplayAction();
    }
 
private:
    Base *pBase;
};
 
int main(){
    User *user = new User(new Derived1());
    user->Action();
    delete user;
}