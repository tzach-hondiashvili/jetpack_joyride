#include "StartGame.h"
#include "Menu.h"

StartGame::StartGame(Menu* menu)
{
	sf::Vector2f position = { 500, 300};
	
	updateSprite(position,&Resources::instance().getOtherTexture(11));
	updateMenu(menu);
}

void StartGame::execute()
{
	getMenu()->resetView();
	getMenu()->getController().getPlayer().resetCoins();
	getMenu()->getController().getMap().resetMap();
	std::unique_ptr temp = std::make_unique<ChooseSkinState>(getMenu());
	getMenu()->updateState(std::move(temp));
}

void StartGame::updateAnimation(bool Switch)
{
	if (Switch)
	{
		updateSprite(getSprite().getPosition(), &Resources::instance().getOtherTexture(12));
	}
	else
	{
		updateSprite(getSprite().getPosition(), &Resources::instance().getOtherTexture(11));
	}
}
