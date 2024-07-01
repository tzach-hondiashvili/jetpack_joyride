#include "Alarm.h"

// Register Coin class with the Factory
bool Alarm::m_registerit = Factory::registerit("Alarm", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Alarm>(position);
    });


Alarm::Alarm(sf::Vector2f position)
{
    updateSprite(position, &Resources::instance().getObjectTexture(5));
    sf::IntRect coinRect(0, 0, getSprite().getTexture()->getSize().x / 6, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(coinRect);
}


void Alarm::show() {
    // Implementation of show function
}

void Alarm::updateAnimation(float)
{
    setAnimationFrame((getAnimationFrame() + 1) % 6);

    int frameWidth = getSprite().getTexture()->getSize().x / 6;

    sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(frameRect);
}
