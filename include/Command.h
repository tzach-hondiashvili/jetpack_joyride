#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class Menu;

class Command 
{
public:
	Command();
	virtual void execute() = 0;
	virtual void updateAnimation(bool Switch) = 0;
	void updateSprite(sf::Vector2f position,sf::Texture* texture);
	Menu* getMenu() const;
	void updateMenu(Menu *menu);
	sf::Sprite& getSprite();
	void setscale(sf::Vector2f scale);

private:
	sf::Sprite m_sprite;
	Menu* m_menu;
};
