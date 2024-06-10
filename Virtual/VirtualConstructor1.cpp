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
    static Base* createInstance(int input);
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
class Derived3 : public Base {
public:
    Derived3() {cout<<"Derived3..."<<endl; }
    ~Derived3(){cout<<"~Derived3..."<<endl; }
    void DisplayAction(){
        cout << "Action from Derived3" << endl;
    }
};

Base* Base::createInstance(int input){
     if(input == 1)
         return new Derived1();
     else if(input == 2)
         return new Derived2();
    else
        return new Derived3();
 }
//// LIBRARY END
 
class User{
public:
 
    // Creates Derived1 or Derived2 based on input
    User() : pBase(nullptr) {
        cout<<"User..."<<endl;
        int input;
        cout<<"Enter ID (1, 2 or 3 only): ";
        cin>>input;
        while( (input !=  1) && (input !=  2) && (input !=  3) ) {
            cout << "Enter ID (1, 2 or 3 only): ";
            cin >> input;
        }
        pBase = Base::createInstance(input);
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
    User *user = new User();
    user->Action();
    delete user;
}