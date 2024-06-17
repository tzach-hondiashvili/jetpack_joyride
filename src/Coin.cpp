#include "Coin.h"

// Register Coin class with the Factory
bool Coin::m_registerit = Factory::registerit("Coin", []() -> std::unique_ptr<GameObjects> 
    {
        return std::make_unique<Coin>();
    });


Coin::Coin() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    m_numPatterns = 4;
    //m_coinShapes.setPrimitiveType(sf::Points);
}


void Coin::show() {
    // Implementation of show function
}
