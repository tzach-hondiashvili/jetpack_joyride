#include "Command.h"

Command::Command()
	:m_menu(nullptr)
{
}

void Command::updateSprite(sf::Vector2f position, sf::Texture* texture, sf::Vector2f size)
{
	m_sprite.setPosition(position);
	m_sprite.setScale(size);
	m_sprite.setTexture(*texture);
}

Menu* Command::getMenu() const
{
	return m_menu;
}

void Command::updateMenu(Menu* menu)
{
	m_menu = menu;
}

sf::Sprite& Command::getSprite()
{
	return m_sprite;
}
