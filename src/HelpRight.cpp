#include "HelpRight.h"
#include "Menu.h"

HelpRight::HelpRight(Menu* menu)
{
	sf::Vector2f position = {1456 - 23, 790 + 150 };

	updateSprite(position, &Resources::instance().getOtherTexture(0));
	updateMenu(menu);
}

void HelpRight::execute()
{
	getMenu()->moveHelpRight();
}
