#pragma once
#include <SFML/Graphics.hpp>
#include "Command.h"

//forward decleration
class Menu;

typedef std::pair<std::string, std::unique_ptr<Command>> option;

class MenuState
{
public:
	MenuState();

	virtual ~MenuState() {};

	void updateMenu(Menu* menu);

	virtual void update(float deltaTime) = 0;
	virtual void print() = 0;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event) = 0;
	virtual void hoverButton(sf::Vector2i position) = 0;
	virtual void moveHelpLeft()	= 0;
	virtual void moveHelpRight() = 0;
	

	Menu* getMenu();

private:
	Menu* m_Menu;
};