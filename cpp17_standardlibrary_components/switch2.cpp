#include <iostream>

enum class Color { Red, Green, Blue };

int main() {
    Color c = Color::Green;

    switch (c) {
        case Color::Red:
            std::cout << "Red selected\n";
            break;
        case Color::Green:
            std::cout << "Green selected\n";
            break;
        case Color::Blue:
            std::cout << "Blue selected\n";
            break;
    }
}