#include "Help.h"
#include "Menu.h"

Help::Help(Menu* menu)
{
	sf::Vector2f position = { 364/2, 110 };
	sf::Vector2f size = { 60 / 364,20 / 240 };

	updateSprite(position, &Resources::instance().getOtherTexture(9), size);
	updateMenu(menu);
}

void Help::execute()
{
	getMenu()->runHelp();
}
