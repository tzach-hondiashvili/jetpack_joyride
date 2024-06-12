#include "Player.h"

Player::Player()
	:m_lives(1)
{
	
}

int Player::getLives() const
{
	return m_lives;
}

void Player::move()
{
}

void Player::createPlayer()
{
	m_playerSprite.setTexture(Resources::instance().getPlayerTexture(7));
	sf::IntRect rect;
	rect.width = m_playerSprite.getTexture()->getSize().x / 4;
	rect.height = m_playerSprite.getTexture()->getSize().y / 1;
	m_flameSprite.setTexture(Resources::instance().getObjectTexture(1));
	m_playerSprite.setTextureRect(rect);
	m_playerSprite.setPosition(150, 150);
}
