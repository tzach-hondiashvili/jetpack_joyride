#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class Menu;

class Command 
{
public:
	Command();
	virtual ~Command() {};

	virtual void execute() = 0;
	virtual void updateAnimation(bool Switch) = 0;
	void updateSprite(sf::Vector2f position,sf::Texture* texture);
	Menu* getMenu() const;
	void updateMenu(Menu *menu);
	sf::Sprite& getSprite();
	void setscale(sf::Vector2f scale);
	void setOrigin(sf::Vector2f origin);
	void adjustRec();

private:
	sf::Sprite m_sprite;
	Menu* m_menu;
};
