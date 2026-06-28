#include <iostream>
#include <cmath>
using namespace std;
class Point {
private:
    float x1, y1;
    Point(float x, float y){
        cout << "private constructor...\n";
        x1 = x;
        y1 = y;
    };
    static Point Polar(float, float);
public:
    //static Point Polar(float, float);
    void display();
    ~Point(){
        cout<<"~Public Destructor..."<<endl;
    }
};

void Point :: display(){
    cout << "x :: " << this->x1 <<endl;
    cout << "y :: " << this->y1 <<endl;
}

Point Point :: Polar(float x, float y){
	cout<<"Polar Coordinate..."<<endl;
    return Point(x*cos(y), x*sin(y));
}

int main(){
    // Polar coordinates
    Point pp = Point::Polar(5.7, 1.2);
    pp.display();
    return 0;
}