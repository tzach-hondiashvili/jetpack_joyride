#include "Coin.h"

// Register Coin class with the Factory
bool Coin::m_registerit = Factory::registerit("Coin", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Coin>(position);
    });


Coin::Coin(sf::Vector2f position)
{
    updateSprite(position,&Resources::instance().getObjectTexture(0));
    sf::IntRect coinRect(0, 0, getSprite().getTexture()->getSize().x / 8, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(coinRect);
}


void Coin::show() {
    // Implementation of show function
}
