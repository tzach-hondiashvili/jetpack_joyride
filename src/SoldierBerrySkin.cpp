#include "SoldierBerrySkin.h"
#include "Menu.h"

SoldierBerrySkin::SoldierBerrySkin(Menu* menu)
{
	sf::Vector2f position = { 1020, 500 };

	updateSprite(position, &Resources::instance().getPlayerTexture(12));
	setscale(sf::Vector2f(100 / float(getSprite().getTexture()->getSize().x), 200 / float(getSprite().getTexture()->getSize().y)));
	updateMenu(menu);
}

void SoldierBerrySkin::execute()
{
	getMenu()->getController().getPlayer().updateSprite(getMenu()->getController().getPlayer().getSprite().getPosition(), &Resources::instance().getPlayerTexture(15));
	getMenu()->getController().getPlayer().setScale(sf::Vector2f(389 / (float)getMenu()->getController().getPlayer().getSprite().getTexture()->getSize().x, 528 / (float)getMenu()->getController().getPlayer().getSprite().getTexture()->getSize().x));
	std::unique_ptr temp = std::make_unique<RunGameState>(getMenu());
	getMenu()->updateState(std::move(temp));
}

void SoldierBerrySkin::updateAnimation(bool Switch)
{

}
