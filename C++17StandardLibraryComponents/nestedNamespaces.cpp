/*

*/

# include <iostream>

// Before C++17:
namespace Game {

    namespace Graphics {

        namespace Physics {

           class TwoD {
           };
        }
    }
}

// in C++17

namespace Game::Graphics::Physics {

    class ThreeD {

    };
}

//using namespace Game::Graphics::Physics;

int main(){

    // TwoD twoD;
    // ThreeD threeD;

    Game::Graphics::Physics::TwoD twoD;
    Game::Graphics::Physics::ThreeD threeD;

    return 0;
}