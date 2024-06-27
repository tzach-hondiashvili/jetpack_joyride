#include "OriginalSkinOption.h"
#include "Menu.h"

OriginalSkinOption::OriginalSkinOption(Menu* menu)
{
	sf::Vector2f position = { 620, 500 };
	setOrigin(sf::Vector2f(50, 100));

	updateSprite(position, &Resources::instance().getPlayerTexture(4));
	setscale({ 1,1 });
	setscale(sf::Vector2f(100 / float(getSprite().getTexture()->getSize().x), 200 / float(getSprite().getTexture()->getSize().y)));
	updateMenu(menu);
}

void OriginalSkinOption::execute()
{
	getMenu()->getController().getPlayer().updateSprite(getMenu()->getController().getPlayer().getSprite().getPosition(), &Resources::instance().getPlayerTexture(7));
	getMenu()->getController().getPlayer().setScale({ 1,1 });
	getMenu()->getController().getPlayer().updateFallingAndDying(&Resources::instance().getPlayerTexture(6), &Resources::instance().getPlayerTexture(5));
	std::unique_ptr temp = std::make_unique<RunGameState>(getMenu());
	getMenu()->updateState(std::move(temp));
}

void OriginalSkinOption::updateAnimation(bool Switch)
{
	if (Switch)
	{
		setscale(sf::Vector2f(150 / float(getSprite().getTexture()->getSize().x), 300 / float(getSprite().getTexture()->getSize().y)));
	}
	else
	{
		setscale(sf::Vector2f(100 / float(getSprite().getTexture()->getSize().x), 200 / float(getSprite().getTexture()->getSize().y)));
	}
}
