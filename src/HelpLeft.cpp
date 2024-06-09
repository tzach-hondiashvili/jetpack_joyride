#include "HelpLeft.h"
#include "Menu.h"

HelpLeft::HelpLeft(Menu* menu)
{
	sf::Vector2f position = {23, 790};

	updateSprite(position, &Resources::instance().getOtherTexture(0));
	updateMenu(menu);
}

void HelpLeft::execute()
{
	getMenu()->moveHelpLeft();
}
