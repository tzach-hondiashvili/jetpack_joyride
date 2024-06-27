#include "Missile.h"
#include "Factory.h"

// Register Coin class with the Factory
bool Missile::m_registerit = Factory::registerit("Missile", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Missile>(position);
    });


Missile::Missile(sf::Vector2f position)
{
	m_beforeMissile.setTexture(Resources::instance().getObjectTexture(7));

	sf::IntRect warningRect(0, 0, m_beforeMissile.getTexture()->getSize().x / 2, m_beforeMissile.getTexture()->getSize().y);
	m_beforeMissile.setTextureRect(warningRect);

	m_beforeMissile.setScale(0.8,0.8);

    updateSprite(position, &Resources::instance().getObjectTexture(6));
    sf::IntRect missileRect(0, 0, getSprite().getTexture()->getSize().x / 7, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(missileRect);
	setOrigin(sf::Vector2f((float)getSprite().getTexture()->getSize().x / 7, (float)getSprite().getTexture()->getSize().y / 2));
}

void Missile::updatebeforeMissile(int index)
{
  
}

void Missile::updateSoundAndWarnings(sf::Vector2f playerpos)
{
	static sf::Sound missileLaunch;
	missileLaunch.setBuffer(Resources::instance().getSoundEffect(4));
	missileLaunch.setVolume(100);

	if (getSprite().getPosition().x >= playerpos.x + 1380) //missile not yet reached
	{
		updateWarningLocation( playerpos + sf::Vector2f(1300,0));
		std::cout << "Incoming!\n";
		setIsPlayed(false);
	}
	else if (getSprite().getPosition().x <= playerpos.x - 128) //end of missile trace
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

sf::Sprite Missile::getWarning()
{
	return m_beforeMissile;
}

void Missile::updateWarningLocation(sf::Vector2f pos)
{
	m_beforeMissile.setPosition({pos.x,getSprite().getPosition().y});
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


	int frameWidth2 = m_beforeMissile.getTexture()->getSize().x / 2;

	sf::IntRect frameRect2(((getAnimationFrame() % 2) + 1) * frameWidth2, 0, frameWidth2, m_beforeMissile.getTexture()->getSize().y);
	m_beforeMissile.setTextureRect(frameRect2);
}


