#include "GameObjects.h"

GameObjects::GameObjects()
	:m_sprite() ,m_animationFrame(0)
{
}

bool GameObjects::CheckIfToDelete(sf::Vector2f viewPos)
{
	if (getSprite().getPosition().x <= viewPos.x-300) //missile passed the screen, end of trace
	{
		return true;
	}
	
	return false;
}

GameObjects::GameObjects(sf::Vector2f position, sf::Texture* texture)
	:m_animationFrame(0)
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

void GameObjects::setOrigin(sf::Vector2f origin)
{
	m_sprite.setOrigin(origin);
}

int GameObjects::getAnimationFrame()
{
	return m_animationFrame;
}

void GameObjects::setAnimationFrame(int frame)
{
	m_animationFrame = frame;
}

void GameObjects::rotate(int angle)
{
	m_sprite.rotate((float)angle);
}


const sf::Sprite& GameObjects::getSprite() const
{
	return m_sprite;
}

void GameObjects::changeSpriteAnimation(sf::IntRect rect)
{
	m_sprite.setTextureRect(rect);
}
