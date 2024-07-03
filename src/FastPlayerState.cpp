#include "FastPlayerState.h"
#include "BasicPlayerState.h"
#include "RunGameState.h"
#include "Resources.h"
#include "Menu.h"

FastPlayerState::FastPlayerState(sf::Vector2f pos, Menu* menu)
	:m_timeInState(0), m_prevSpeed(0)
{
	updateMenu(menu);
	updateCurrSkin(&Resources::instance().getPlayerTexture(20), { pos.x, pos.y });
	getCurrSkin().setScale({ 2,2 });
	getGravity() -= 400;
	//getCurrSkin().setTexture(Resources::instance().getPlayerTexture(20));
	auto runGame = dynamic_cast<RunGameState*>(getMenu()->getState().get());
	m_prevSpeed = runGame->getScrollSpeed();
	runGame->setScrollSpeed(m_prevSpeed * 5);
	
	getMenu()->getController().setIfCheckCollision(false);
}

void FastPlayerState::updateAnimation(float time)
{
	m_timeInState += time;
	if (m_timeInState >= 5.f)
	{
		auto runGame = dynamic_cast<RunGameState*>(getMenu()->getState().get());
		runGame->setScrollSpeed(m_prevSpeed);

		//exit state
		getMenu()->getController().getPlayer().getState() = std::move(std::make_unique<BasicPlayerState>(getCurrSkin().getPosition(), getMenu()));
		return;
	}
	applyGravity(time);
	handleInput();
}




void FastPlayerState::move(sf::Vector2f pos, float time)
{
	getCurrSkin().setPosition({ pos.x - 130, getCurrSkin().getPosition().y });
	

	sf::Vector2f newPosition = getCurrSkin().getPosition();
	newPosition.y += getVelocity().y * time;

	if (newPosition.y > 750)
	{
		newPosition.y = 750;
		getVelocity().y = 0;
	}
	else if (newPosition.y < 30)
	{
		newPosition.y = 30;
		getVelocity().y = 0;
	}
	getCurrSkin().setPosition(newPosition);

	updateAnimation(time);
}

void FastPlayerState::print()
{
	getMenu()->getWindow().draw(getCurrSkin());
}
