#include "Scoreboard.h"
#include <string>
#include "Resources.h"

Scoreboard::Scoreboard()
	:m_coinsCounter(),m_distanceCounter(),m_lives()
{
	m_coinsCounter.setFont(Resources::instance().getFont());
	m_distanceCounter.setFont(Resources::instance().getFont());
	m_lives.setFont(Resources::instance().getFont());

	m_distanceCounter.setCharacterSize(40);
	m_distanceCounter.setOutlineThickness(6);
	m_distanceCounter.setOutlineColor(sf::Color::Black);

}

void Scoreboard::updateDistance(float distance,sf::Vector2f newpos)
{
	m_distanceCounter.setString("Distance: " + std::to_string((int)distance/100)+"M");
	m_distanceCounter.setPosition({newpos.x - 80,newpos.y - 730});
}

const sf::Text& Scoreboard::getDistance() const
{
	return m_distanceCounter;
}
