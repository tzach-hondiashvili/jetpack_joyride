#include "Missile.h"

// Register Coin class with the Factory
bool Missile::m_registerit = Factory::registerit("Missile", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Missile>(position);
    });


Missile::Missile(sf::Vector2f position)
    :m_beforeMissile(&Resources::instance().getObjectTexture(8))
{
    updateSprite(position, &Resources::instance().getObjectTexture(6));
    sf::IntRect missileRect(0, 0, getSprite().getTexture()->getSize().x / 7, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(missileRect);
    setOrigin(sf::Vector2f(getSprite().getTexture()->getSize().x / 7, getSprite().getTexture()->getSize().y / 2));
}

void Missile::updatebeforeMissile(int index)
{
  
}

void Missile::move(sf::Vector2f pos, float time)
{
    updateSpritePos({pos.x - 700*time, pos.y });
}

void Missile::show() {
    // Implementation of show function
}

void Missile::updateAnimation(float time)
{
    setAnimationFrame((getAnimationFrame() + 1) % 7);

    int frameWidth = getSprite().getTexture()->getSize().x / 7;

    sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(frameRect);
}
