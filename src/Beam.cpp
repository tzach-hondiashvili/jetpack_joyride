#include "Beam.h"

// Register Coin class with the Factory
bool Beam::m_registerit = Factory::registerit("Beam", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Beam>(position);
    });


Beam::Beam(sf::Vector2f position)
{
    updateSprite(position, &Resources::instance().getObjectTexture(4));
    sf::IntRect lazerRect(0, 0, getSprite().getTexture()->getSize().x / 4, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(lazerRect);
    setOrigin(sf::Vector2f(getSprite().getTexture()->getSize().x / 8, getSprite().getTexture()->getSize().y / 2));
}

void Beam::show() {
    // Implementation of show function
}

void Beam::updateAnimation(float time)
{
    setAnimationFrame((getAnimationFrame() + 1) % 4);

    int frameWidth = getSprite().getTexture()->getSize().x / 4;

    sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(frameRect);
}

