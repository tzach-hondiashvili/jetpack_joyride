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
	static sf::Sound Click;
	Click.setBuffer(Resources::instance().getSoundEffect(7));
	Click.setVolume(100);
	Click.play();

	getMenu()->getState()->moveHelpRight();
}
