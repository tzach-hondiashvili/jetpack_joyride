#include "SpeedBoost.h"
#include "Pickable.h"
#include <iostream>
#include "Factory.h"
#include "Resources.h"
#include <cstdlib>
#include <ctime>   

// Register Coin class with the Factory
bool SpeedBoost::m_registerit = Factory::registerit("SpeedBoost", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<SpeedBoost>(position);
    });


SpeedBoost::SpeedBoost(sf::Vector2f position)
{
    updateSprite(position, &Resources::instance().getObjectTexture(11));
    setScale({ 0.18,0.18 });
    sf::IntRect SpeedBoostRect(0, 0, getSprite().getTexture()->getSize().x, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(SpeedBoostRect);
}
