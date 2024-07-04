#include "Missile.h"
#include "Factory.h"

// Register Coin class with the Factory
bool Missile::m_registerit = Factory::registerit("Missile", [](sf::Vector2f position) -> std::unique_ptr<GameObjects>
    {
        return std::make_unique<Missile>(position);
    });


Missile::Missile(sf::Vector2f position)
{
	m_MissileLaunch.setBuffer(Resources::instance().getSoundEffect(4));
	m_MissileLaunch.setVolume(100);
	m_MissileWarning.setBuffer(Resources::instance().getSoundEffect(3));
	m_MissileWarning.setVolume(50);
	m_MissileWarning.setLoop(false);

	m_beforeMissile.setTexture(Resources::instance().getObjectTexture(8));
	m_warningMissile.setTexture(Resources::instance().getObjectTexture(7));

	sf::IntRect warningRect1(0, 0, m_beforeMissile.getTexture()->getSize().x / 2, m_beforeMissile.getTexture()->getSize().y);
	m_beforeMissile.setTextureRect(warningRect1);

	sf::IntRect warningRect2(0, 0, m_warningMissile.getTexture()->getSize().x / 2, m_warningMissile.getTexture()->getSize().y);
	m_beforeMissile.setTextureRect(warningRect2);

	m_beforeMissile.setScale((float)0.8, (float)0.8);
	m_warningMissile.setScale((float)0.8, (float)0.8);

    updateSprite(position, &Resources::instance().getObjectTexture(6));
    sf::IntRect missileRect(0, 0, getSprite().getTexture()->getSize().x / 7, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(missileRect);
	setOrigin(sf::Vector2f((float)getSprite().getTexture()->getSize().x / 7, (float)getSprite().getTexture()->getSize().y / 2));
}

void Missile::updateSoundAndWarnings(sf::Vector2f playerpos)
{
	if (getSprite().getPosition().x >= playerpos.x + 1300) //missile not yet reached
	{
		updateWarningLocation( playerpos + sf::Vector2f(1250,0));

		if (!getIsWarningPlayed() && (getSprite().getPosition().x <= playerpos.x + 1980))
		{
			m_beforeMissile.setTexture(Resources::instance().getObjectTexture(7));
			m_MissileWarning.play();
			setIsWarningPlayed(true);
		}
	}
	else if (getSprite().getPosition().x <= playerpos.x - 128) //end of missile trace
	{

	}
	else
	{
		if (!getIsLaunchPlayed())
		{
			m_MissileLaunch.play();
			setIsLaunchPlayed(true);
			m_MissileWarning.setLoop(false);
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

sf::Sprite Missile::getBeforeMissile()
{
	return m_warningMissile;
}

void Missile::updateBeforeLocation(sf::Vector2f pos)
{
	m_warningMissile.setPosition({ pos.x,getSprite().getPosition().y });
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
    //setAnimationFrame((getAnimationFrame() + 1) % 7);
	//
    //int frameWidth = getSprite().getTexture()->getSize().x / 7;
	//
    //sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
    //changeSpriteAnimation(frameRect);
	//
	//
	//int frameWidth2 = m_beforeMissile.getTexture()->getSize().x / 2;
	//
	//sf::IntRect frameRect2(((getAnimationFrame() % 2) + 1) * frameWidth2, 0, frameWidth2, m_beforeMissile.getTexture()->getSize().y);
	//m_beforeMissile.setTextureRect(frameRect2);
	// Assuming there are 7 frames for the missile and 2 frames for the warning
	const int missileFrameCount = 7;
	const int warningFrameCount = 2;

	// Update the missile animation frame
	setAnimationFrame((getAnimationFrame() + 1) % missileFrameCount);
	int frameWidth = getSprite().getTexture()->getSize().x / missileFrameCount;
	sf::IntRect missileFrameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
	changeSpriteAnimation(missileFrameRect);

	// Update the warning animation frame
	int warningFrameWidth = m_beforeMissile.getTexture()->getSize().x / warningFrameCount;
	sf::IntRect warningFrameRect((getAnimationFrame() % warningFrameCount) * warningFrameWidth, 0, warningFrameWidth, m_beforeMissile.getTexture()->getSize().y);
	m_beforeMissile.setTextureRect(warningFrameRect);
}


