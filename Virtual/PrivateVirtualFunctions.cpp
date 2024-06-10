#include <iostream>
 
class base {
public:
     base() { 
         std::cout << "base class constructor\n"; }
     virtual ~base(){
        std::cout << "base class destructor\n"; }
    void show(){
        std::cout << "show() called on base class\n"; }
    virtual void print() {
        std::cout << "print() called on base class\n";
    }
};
 
class derived : public base {
public:
    derived(): base() {
        std::cout << "derived class constructor\n";
    }
    virtual ~derived() {
        std::cout << "derived class destructor\n";
    }
    
        void show(){
        std::cout << "show() called on derived class\n"; }
 
private:
    // private virtual function in derived class overwrites
    // base class virtual method contents of this function
    // are printed when called with base class pointer or
    // when called with derived class object
    virtual void print() {
        std::cout << "print() called on derived class\n";
    }
};
 
int main(){
    base* b_ptr = new derived();
 
    b_ptr->show();
 
    // call virtual print in base class but it is overridden
    // in derived class also note that print() is private
    // member in derived class, still the contents of
    // derived class are printed this code works because
    // base class defines a public interface and drived
    // class overrides it in its implementation
    b_ptr->print();
 
    delete b_ptr;
}