#include "Scoreboard.h"
#include <string>
#include "Resources.h"

Scoreboard::Scoreboard()
	:m_coinsCounter(),m_distanceCounter(),m_lives()
{
	m_coinsCounter.setFont(Resources::instance().getFont());
	m_distanceCounter.setFont(Resources::instance().getFont());
	m_lives.setFont(Resources::instance().getFont());
}

void Scoreboard::updateDistance(float distance)
{
	m_coinsCounter.setString(std::to_string(distance));
}
