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
#include "Scoreboard.h"
#include "HelpState.h"
#include "MenuState.h"
#include "RunGameState.h"
#include "DefaultMenu.h"

typedef std::pair<std::string, std::unique_ptr<Command>> option;

class Menu
{
public:
	Menu();

	void runMenu();
	void quitGame();

	bool finishedLoading();
	void updateController(sf::Vector2f pos, float time);
	void printScoreBoard();
	void updateScoreBoard();
	void printPlayer();

	Controller& getController();
	sf::RenderWindow& getWindow();
	std::unique_ptr<MenuState>&getState();

	void updateState(std::unique_ptr<MenuState> state);


private:
	sf::RenderWindow m_window;

	Controller m_controller;
	Scoreboard m_scoreBoard;
	LoadingScreen m_loadingScreen;
	std::unique_ptr<MenuState> m_state;

	bool m_finishedLoading;
};