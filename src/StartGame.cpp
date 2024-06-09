#include "StartGame.h"
#include "Menu.h"

StartGame::StartGame(Menu* menu)
{
	sf::Vector2f position = {364/2,80};
	sf::Vector2f size = {60/364,20/240};
	
	updateSprite(position,&Resources::instance().getOtherTexture(11),size);
	updateMenu(menu);
}

void StartGame::execute()
{
	getMenu()->runGame();
}
