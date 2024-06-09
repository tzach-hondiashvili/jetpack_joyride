#include "Quit.h"
#include "Menu.h"

Quit::Quit(Menu* menu)
{
	sf::Vector2f position = { 364 / 2, 140 };
	sf::Vector2f size = { 60 / 364,20 / 240 };

	updateSprite(position, &Resources::instance().getOtherTexture(9), size);
	updateMenu(menu);
}

void Quit::execute()
{
	getMenu()->quitGame();
}
