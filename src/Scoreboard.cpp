#include "Scoreboard.h"
#include <string>
#include "Resources.h"

Scoreboard::Scoreboard()
	:m_coinsCounter(),m_distanceCounter()
{
	m_coinsCounter.setFont(Resources::instance().getFont());
	m_distanceCounter.setFont(Resources::instance().getFont());
	

	m_distanceCounter.setCharacterSize(40);
	m_distanceCounter.setOutlineThickness(6);
	m_distanceCounter.setOutlineColor(sf::Color::Black);

	m_coinsCounter.setCharacterSize(40);
	m_coinsCounter.setOutlineThickness(6);
	m_coinsCounter.setOutlineColor(sf::Color::Black);

}

void Scoreboard::updateCoins(int numOfCoins)
{
	m_coinsCounter.setString("COINS: " + std::to_string(numOfCoins));
	m_coinsCounter.setPosition(m_distanceCounter.getPosition() + sf::Vector2f(0, 50));
}

void Scoreboard::updateDistance(float distance,sf::Vector2f newpos)
{
	m_distanceCounter.setString("Distance: " + std::to_string((int)distance/100)+"M");
	m_distanceCounter.setPosition({newpos.x - 80,20});
}

const sf::Text& Scoreboard::getDistance() const
{
	return m_distanceCounter;
}

const sf::Text& Scoreboard::getCoinsCounter() const
{
	return m_coinsCounter;
}
