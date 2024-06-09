#include "Help.h"
#include "Menu.h"

Help::Help(Menu* menu)
{
	sf::Vector2f position = { 500, 500 };


	updateSprite(position, &Resources::instance().getOtherTexture(9));
	updateMenu(menu);
}

void Help::execute()
{
	getMenu()->runHelp();
}
