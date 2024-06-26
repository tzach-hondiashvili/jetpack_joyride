#include "PowerUp.h"
#include "Pickable.h"
#include <iostream>
#include "Factory.h"
#include "Resources.h"
#include <cstdlib>
#include <ctime>   

// Register Coin class with the Factory
bool PowerUp::m_registerit = Factory::registerit("PowerUp", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<PowerUp>(position);
    });


PowerUp::PowerUp(sf::Vector2f position)
{
    updateSprite(position, &Resources::instance().getObjectTexture(10));
    sf::IntRect PowerUpRect(0, 0, getSprite().getTexture()->getSize().x, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(PowerUpRect);
}
