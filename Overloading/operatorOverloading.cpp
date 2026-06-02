#include <cassert>
#include <iostream>
using namespace std;

class IntToDuble{
    private:
        int m_numerator;
        int m_denominator;
    
    public:
        IntToDuble(int numerator = 0, int denominator = 1):m_numerator(numerator),m_denominator(denominator){
            std::cout<<"Constructor..."<<endl;
            if(m_denominator == 0)
                assert(denominator != 0);
        }
        
        IntToDuble(const IntToDuble& obj){
            cout<<"CopyConstructor..."<<endl;
            m_numerator = obj.m_numerator;
            m_denominator = obj.m_denominator;
        }
        friend ostream& operator<<(std::ostream& out, const IntToDuble& f1);
};

void printFraction(const IntToDuble& obj){
    cout<<obj<<endl;
}

ostream & operator <<(ostream& out, const IntToDuble& obj){
    out<<obj.m_numerator<<'/'<<obj.m_denominator;
    return out;
}

int main(){
    
    IntToDuble i2d(10);
    printFraction(i2d);
    printFraction(10);
    
    return 0;
}