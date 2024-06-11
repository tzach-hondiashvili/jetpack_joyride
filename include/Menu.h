#pragma once
#include "Controller.h"
#include "Help.h"
#include "StartGame.h"
#include "Return2Menu.h"
#include "HelpLeft.h"
#include "HelpRight.h"
#include <iostream>
#include <string>
#include <future>
#include <thread>
#include "LoadingScreen.h"

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
	void handleHelpButtonClick(const sf::Event::MouseButtonEvent& event);
	void showHelpButtons();
	void return2Menu();
	void moveHelpLeft();
	void moveHelpRight();

private:
	sf::RenderWindow m_window;
	std::vector<option> m_options;
	std::vector<option> m_helpButtons;
	LoadingScreen m_loadingScreen;


	bool m_runHelp;
	unsigned m_helpPage;
};