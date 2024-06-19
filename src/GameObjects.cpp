#include "GameObjects.h"

GameObjects::GameObjects()
	:m_sprite()
{
}

GameObjects::GameObjects(sf::Vector2f position, sf::Texture* texture)
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(*texture);
}

void GameObjects::updateSprite(sf::Vector2f position, sf::Texture* texture)
{
	m_sprite.setPosition(position);
	m_sprite.setTexture(*texture);
}

void GameObjects::updateSpritePos(sf::Vector2f position)
{
	m_sprite.setPosition(position);
}

void GameObjects::setScale(sf::Vector2f scale)
{
	m_sprite.setScale(scale);
}


const sf::Sprite& GameObjects::getSprite() const
{
	return m_sprite;
}

void GameObjects::changeSpriteAnimation(sf::IntRect rect)
{

	m_sprite.setTextureRect(rect);
}
