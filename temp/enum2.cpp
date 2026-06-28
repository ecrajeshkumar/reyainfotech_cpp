#include <iostream>
#include <string_view>

//using namespace std;

enum class Color{
    black = 1,
    red,
    blue,
};

constexpr std::string_view getColor(Color color) {
    using enum  Color

    switch (color) {
    case black: return "black"; // note: black instead of Color::black
    case red:   return "red";
    case blue:  return "blue";
    default:    return "???";
    }
}

int main() {
    Color shirt{ Color::blue };

    std::cout << "Your shirt is " << getColor(shirt) << '\n';

    return 0;
}