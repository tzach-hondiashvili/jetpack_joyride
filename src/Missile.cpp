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
    setOrigin(sf::Vector2f((float)getSprite().getTexture()->getSize().x / 7, (float)getSprite().getTexture()->getSize().y / 2));
}

void Missile::updatebeforeMissile(int index)
{
  
}

void Missile::updateSoundAndWarnings(sf::Vector2f pos)
{
	static sf::Sound missileLaunch;
	missileLaunch.setBuffer(Resources::instance().getSoundEffect(4));
	missileLaunch.setVolume(100);

	if (getSprite().getPosition().x >= pos.x + 1328) //beginning of missile trace
	{
		std::cout << "Incoming!\n";
		setIsPlayed(false);
	}
	else if (getSprite().getPosition().x <= pos.x - 128) //end of missile trace
	{

	}
	else
	{
		if (!getIsPlayed())
		{
			std::cout << "Missile!\n";
			missileLaunch.play();
			setIsPlayed(true);
		}
	}
}

void Missile::move(sf::Vector2f pos, float time)
{
    updateSpritePos({pos.x - 700*time, pos.y });
}

void Missile::show() {
    // Implementation of show function
}

void Missile::updateAnimation(float )
{
    setAnimationFrame((getAnimationFrame() + 1) % 7);

    int frameWidth = getSprite().getTexture()->getSize().x / 7;

    sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(frameRect);
}


