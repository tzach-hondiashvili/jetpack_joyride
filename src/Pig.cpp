#include "Pig.h"
#include "Pickable.h"
#include <iostream>
#include "Factory.h"
#include "Resources.h"
#include <cstdlib>
#include <ctime>   

// Register Coin class with the Factory
bool Pig::m_registerit = Factory::registerit("Pig", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Pig>(position);
    });


Pig::Pig(sf::Vector2f position)
{
    updateSprite(position, &Resources::instance().getObjectTexture(9));
    sf::IntRect PigRect(0, 0, getSprite().getTexture()->getSize().x, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(PigRect);
}
