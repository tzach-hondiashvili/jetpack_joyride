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

const sf::Sprite& GameObjects::getSprite() const
{
	return m_sprite;
}

void GameObjects::changeSpriteAnimation(sf::IntRect rect)
{
	m_sprite.setTextureRect(rect);
}
