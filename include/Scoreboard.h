#pragma once
#include <SFML/Graphics.hpp>

class Scoreboard
{
public:
	Scoreboard();
	void updateCoins(int numOfCoins);
	void updateLives(int lives);
	void updateDistance(float distance);

private:
	sf::Text m_distanceCounter, m_coinsCounter, m_lives;
};