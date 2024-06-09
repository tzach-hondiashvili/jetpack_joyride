#include "Return2Menu.h"
#include "Menu.h"

Return2Menu::Return2Menu(Menu* menu)
{
	sf::Vector2f position = { 23, 30 };

	updateSprite(position, &Resources::instance().getOtherTexture(0));
	updateMenu(menu);
}

void Return2Menu::execute()
{
	getMenu()->return2Menu();
}
