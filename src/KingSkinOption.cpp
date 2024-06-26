#include "KingSkinOption.h"
#include "Menu.h"

KingSkinOption::KingSkinOption(Menu* menu)
{
	sf::Vector2f position = { 420, 500 };

	setOrigin(sf::Vector2f(50,100));

	updateSprite(position, &Resources::instance().getPlayerTexture(0));
	setscale(sf::Vector2f(100 / float(getSprite().getTexture()->getSize().x), 200 / float(getSprite().getTexture()->getSize().y)));

	updateMenu(menu);
}

void KingSkinOption::execute()
{
	getMenu()->getController().getPlayer().updateSprite(getMenu()->getController().getPlayer().getSprite().getPosition(), &Resources::instance().getPlayerTexture(3));
	getMenu()->getController().getPlayer().setScale(sf::Vector2f(389 / (float)getMenu()->getController().getPlayer().getSprite().getTexture()->getSize().x, 528 / (float)getMenu()->getController().getPlayer().getSprite().getTexture()->getSize().x));
	getMenu()->getController().getPlayer().updateFallingAndDying(&Resources::instance().getPlayerTexture(2),&Resources::instance().getPlayerTexture(1));
	std::unique_ptr temp = std::make_unique<RunGameState>(getMenu());
	getMenu()->updateState(std::move(temp));
}

void KingSkinOption::updateAnimation(bool Switch)
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
