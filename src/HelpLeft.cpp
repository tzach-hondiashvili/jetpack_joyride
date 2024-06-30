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
	static sf::Sound Click;
	Click.setBuffer(Resources::instance().getSoundEffect(7));
	Click.setVolume(100);
	Click.play();

	getMenu()->getState()->moveHelpLeft();
}
