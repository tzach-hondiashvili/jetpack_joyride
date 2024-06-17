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
	std::unique_ptr<MenuState> temp = std::make_unique<HelpState>(getMenu());
	getMenu()->updateState(std::move(temp));
}

void Help::updateAnimation(bool Switch)
{
	if (Switch)
	{
		updateSprite(getSprite().getPosition(),&Resources::instance().getOtherTexture(10));
	}
	else
	{
		updateSprite(getSprite().getPosition(), &Resources::instance().getOtherTexture(9));
	}
}
