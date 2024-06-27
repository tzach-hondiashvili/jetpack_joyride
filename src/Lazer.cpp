#include "Lazer.h"
#include "Lazer.h"

// Register Coin class with the Factory
bool Lazer::m_registerit = Factory::registerit("Lazer", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Lazer>(position);
    });


Lazer::Lazer(sf::Vector2f position)
{
    updateSprite(position, &Resources::instance().getObjectTexture(3));
    sf::IntRect lazerRect(0, 0, getSprite().getTexture()->getSize().x / 4, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(lazerRect);
    setOrigin( sf::Vector2f((float)getSprite().getTexture()->getSize().x / 8, (float)getSprite().getTexture()->getSize().y/2 ));
}

void Lazer::show() {
    // Implementation of show function
}

void Lazer::updateAnimation(float )
{
    //setAnimationFrame((getAnimationFrame() + 1) % 4);

    //int frameWidth = getSprite().getTexture()->getSize().x / 4;

    //sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
    //changeSpriteAnimation(frameRect);
}
