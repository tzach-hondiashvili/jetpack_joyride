#pragma once
#include "Controller.h"
#include "Help.h"
#include "StartGame.h"
#include <iostream>

typedef std::pair<std::string, std::unique_ptr<Command>> option;

class Menu
{
public:
	Menu();
	void runGame();
	void runMenu();
	void runHelp();
	void quitGame();
	void show();
	void updateOptions();
	void handleButtonClick(const sf::Event::MouseButtonEvent& event);

private:
	sf::RenderWindow m_window;
	std::vector<option> m_options;
};