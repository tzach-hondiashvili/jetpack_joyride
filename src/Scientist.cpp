#include "Scientist.h"

// Register Coin class with the Factory
bool Scientist::m_registerit = Factory::registerit("Scientist", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Scientist>(position);
    });


Scientist::Scientist(sf::Vector2f position)
    :m_isLeft(false)
{
    std::srand((unsigned int)std::time(NULL));
    int randomNumber = (std::rand() % 3) + 1;
    setAnimationFrame(randomNumber); 
    updateSprite(position, &Resources::instance().getOtherTexture(15));

    //when the x is odd the scientist will go right so i mirror them
    if (int(position.x) % 2 != 0)
    {
        setScale({ -1, 1 });
        m_isLeft = true;
    }
    
    sf::IntRect ScientistRect(0, 0, getSprite().getTexture()->getSize().x / 3, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(ScientistRect);
}


void Scientist::show() {
    // Implementation of show function
}

void Scientist::updateAnimation(float)
{
    setAnimationFrame((getAnimationFrame() + 1) % 3);

    int frameWidth = getSprite().getTexture()->getSize().x / 3;

    sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(frameRect);
}

void Scientist::move(sf::Vector2f pos, float time)
{
    std::srand((unsigned int)std::time(NULL));
    int randomNumber = (std::rand() % 200) + 100;

    if (m_isLeft)//going right
    {
        updateSpritePos({ pos.x + randomNumber * time, pos.y });
    }
    else//going left
    {
        updateSpritePos({ pos.x - randomNumber * time, pos.y });
    }
}