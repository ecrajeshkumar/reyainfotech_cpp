#include <iostream>
using namespace std;
 
class Distance {
   private:
      int feet;
      int inches;
      int meter;
      
   public:
      Distance() {
         cout<<"Default constructors..."<<endl;
         feet = 0;
         inches = 0;
         meter = 0;
      }
      Distance(int f, int i) {
         cout<<"Two parameter constructors..."<<endl;
         feet = f;
         inches = i;
      }
      
       Distance(int f, int i, int m) {
         cout<<"Three parameter constructors..."<<endl;
         feet = f;
         inches = i;
         meter = m;
      }
      
      // overload function call
      Distance & operator()(int a, int b, int c) {
         Distance D;
         
         D.feet = a + c;
         D.inches = b + c;
         return D;
      }
      
      // method to display distance
      void displayDistance() {
         cout << "F: " << feet << " I:" << inches << " M:"<<meter<<endl;
      }   
};

int main() {
   Distance D1, D2(10, 20);

   cout << "First Distance : "; 
   D1.displayDistance();
   cout << "Second Distance : ";
   D2.displayDistance();
   
   
   D1 = D2(30, 40, 10); // invoke operator()
   cout << "Third Distance :"; 
   D1.displayDistance();

   return 0;
}