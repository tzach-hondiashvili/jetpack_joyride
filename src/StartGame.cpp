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
	getMenu()->runGame();
}
