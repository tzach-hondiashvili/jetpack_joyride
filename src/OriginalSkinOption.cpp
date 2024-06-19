#include "OriginalSkinOption.h"
#include "Menu.h"

OriginalSkinOption::OriginalSkinOption(Menu* menu)
{
	sf::Vector2f position = { 620, 500 };

	updateSprite(position, &Resources::instance().getPlayerTexture(4));
	setscale(sf::Vector2f(100 / float(getSprite().getTexture()->getSize().x), 200 / float(getSprite().getTexture()->getSize().y)));
	updateMenu(menu);
}

void OriginalSkinOption::execute()
{
	getMenu()->getController().getPlayer().updateSprite(getMenu()->getController().getPlayer().getSprite().getPosition(), &Resources::instance().getPlayerTexture(7));
	std::unique_ptr temp = std::make_unique<RunGameState>(getMenu());
	getMenu()->updateState(std::move(temp));
}

void OriginalSkinOption::updateAnimation(bool Switch)
{

}
