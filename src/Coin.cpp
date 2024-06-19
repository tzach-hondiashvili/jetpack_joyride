#include "Coin.h"

// Register Coin class with the Factory
bool Coin::m_registerit = Factory::registerit("Coin", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Coin>();
    });


Coin::Coin() 
{

}


void Coin::show() {
    // Implementation of show function
}
