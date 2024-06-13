#include "Player.h"

Player::Player()
	:m_lives(1)
{
	
}

int Player::getLives() const
{
	return m_lives;
}

void Player::move(sf::Vector2f pos, float time)
{
	static int currFrame = 0;

	updateSpritePos({ pos.x,750 });

	static float timeSinceLastFrame = 0.f;
	timeSinceLastFrame += time;

	if (timeSinceLastFrame >= 0.18)
	{
		// Move to the next frame
		currFrame = (currFrame + 1) % 3;

		// Update the texture rectangle

		sf::IntRect frameRect(currFrame * getSprite().getTextureRect().width, 0, getSprite().getTextureRect().width, getSprite().getTextureRect().height);

		changeSpriteAnimation(frameRect);

		// Reset the time since last frame
		timeSinceLastFrame = 0.f;
	}
}

void Player::createPlayer()
{

	updateSprite({ 150, 750 }, &Resources::instance().getPlayerTexture(7));

	sf::IntRect rect;
	rect.width = getSprite().getTexture()->getSize().x / 4;
	rect.height = getSprite().getTexture()->getSize().y / 1;

	m_flameSprite.setTexture(Resources::instance().getObjectTexture(1));

	changeSpriteAnimation(rect);
}

bool Player::isFying()
{
	return getSprite().getPosition().y < 750;
}
