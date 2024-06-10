
#include <iostream>

using namespace std;

enum class Animals {
    chicken, // 0
    dog, // 1
    cat, // 2
    elephant, // 3
    duck, // 4
    snake, // 5

    maxAnimals,
};

constexpr auto operator+(Animals a) noexcept {
    return static_cast<std::underlying_type_t<Animals>>(a);
}
    
int main(){
    
    //unscoped enumeration
/*    enum Fruit{
        apple = 1,
        orange = 2,
    };
    enum Color{
        red = 1,
        yellow = 2,
    };
    Fruit fruit{apple};
    Color color{red};
    
    if(fruit == color){
    //if(apple == yellow){
        cout<<"fruit color is same"<<endl;
    }else{
        cout<<"fruit color is not same"<<endl;
    }*/
    //scoped enumeration
    enum class Fruit{
        apple = 1,
        orange = 2,
    };
    enum class Color{
        red = 1,
        yellow,
        blue,
    };
    Fruit fruit{Fruit::apple};
    Color color{Color::red};
    
/*    //if(fruit == color){  // compile error: the compiler doesn't know how to compare different types Color and Fruit
    if(Fruit::apple == Color::yellow){ 
        cout<<"fruit color is same"<<endl;
    }else{
        cout<<"fruit color is not same"<<endl;
    }*/
    
    //cout<<Fruit::apple<<endl;
    //std::cout << color << '\n';  // won't work, because there's no implicit conversion to int
    std::cout << static_cast<int>(color) << endl;

    Color shirt { Color::red };
    shirt = { Color::blue };
    if (shirt == Color::red)     // this Color to Color comparison is okay because same scope
        std::cout << "The shirt is red!\n";
    else if (shirt == Color::blue)
        std::cout << "The shirt is blue!\n";
    
    int input{};
    cout<<"Enter your choice of shirt color{red{1}, yellow{2}, blue{3}"<<endl;
    cin>>input;
    shirt = {static_cast<Color>(input)};
    cout<<"Your choice of shirt color is: "<<static_cast<int>(shirt)<<endl;
    
   
    std::cout << +Animals::elephant << '\n'; // convert Animals::elephant to an integer using unary operator+
    
    
    
    return 0;
}