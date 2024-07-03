#include "FastPlayerState.h"
#include "Resources.h"|B
#include "Menu.h"

FastPlayerState::FastPlayerState(sf::Vector2f pos, Menu* menu)
	:m_timeInState(0)
{
	getCurrSkin().setTexture(Resources::instance().getPlayerTexture(20));
}

void FastPlayerState::move(sf::Vector2f, float time)
{
	m_timeInState += time;

}

void FastPlayerState::print()
{
	getMenu()->getWindow().draw(getCurrSkin());
}
