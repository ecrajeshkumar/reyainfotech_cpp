/*
 * In C++, dynamic casting is mainly used for safe downcasting at run time. 
 * To work on dynamic_cast there must be one virtual function in the base class. 
 * A dynamic_cast works only polymorphic base class because it uses this information to decide safe 
 * downcasting.
 * As we mention above for dynamic casting there must be one Virtual function. Suppose If we do not use the virtual function, then what is the result?
 * In that case, it generates an error message “Source type is not polymorphic”.
 * A Dynamic_cast has runtime overhead because it checks object types at run time using “Run-Time Type Information“.
 * If there is a surety we will never cast to wrong object then always avoid dynamic_cast and use static_cast.
*/

#include <iostream>
using namespace std;

class Base{
public:
    //void display(){
    virtual void display(){
        cout<<"from Base..."<<endl;
    }
};
class Derived_1 : public Base{
public:
    void display(){
        cout<<"from Derived_1..."<<endl;
    }
};
class Derived_2 : public Base{
public:
    void display(){
        cout<<"from Derived_2..."<<endl;
    }
};

int main(){
    
    Derived_1 d1;
    d1.display();
    Base *bp = dynamic_cast<Base*>(&d1);
    bp->display();
    Derived_2 *dp2 = dynamic_cast<Derived_2*>(bp);  //if not virtual then compiler error
    if(dp2 == nullptr){
        cout<<"nullptr..."<<endl;
        Derived_1 *dp1 = dynamic_cast<Derived_1*>(bp);
        dp1->display();
    }else{
        cout<<"not nullptr"<<endl;
        dp2->display();
    }
    
    try{
        Derived_2 &dr2 = dynamic_cast<Derived_2&>(d1);
        dr2.display();
    }catch(exception &e){
        cout<<e.what()<<endl;
    }
    
    return 0;
}