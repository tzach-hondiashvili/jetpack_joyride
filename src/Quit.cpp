#include "Quit.h"
#include "Menu.h"

Quit::Quit(Menu* menu)
{
	sf::Vector2f position = { 364 / 2, 140 };

	updateSprite(position, &Resources::instance().getOtherTexture(9));
	updateMenu(menu);
}

void Quit::execute()
{
	getMenu()->quitGame();
}
