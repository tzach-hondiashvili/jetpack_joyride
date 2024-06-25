#include "Missile.h"

// Register Coin class with the Factory
bool Missile::m_registerit = Factory::registerit("Missile", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Missile>(position);
    });


Missile::Missile(sf::Vector2f position)
{
    updateSprite(position, &Resources::instance().getObjectTexture(6));
    sf::IntRect missileRect(0, 0, getSprite().getTexture()->getSize().x / 7, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(missileRect);
    setOrigin(sf::Vector2f(getSprite().getTexture()->getSize().x / 7, getSprite().getTexture()->getSize().y / 2));
}

void Missile::move(sf::Vector2f pos, float time)
{
    updateSpritePos({ getSprite().getPosition().x, pos.x });

    updateAnimation(time);

    sf::Vector2f newPosition = getSprite().getPosition();
    newPosition.x += 5 * time;

    // Clamp the missile's position
    if (newPosition.y > 750) {
        newPosition.y = 750;
    }
    else if (newPosition.y < 30) {
        newPosition.y = 30;
    }
    updateSpritePos(newPosition);
}

void Missile::show() {
    // Implementation of show function
}

void Missile::updateAnimation(float time)
{
    //setAnimationFrame((getAnimationFrame() + 1) % 4);

    //int frameWidth = getSprite().getTexture()->getSize().x / 4;

    //sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
    //changeSpriteAnimation(frameRect);
}
