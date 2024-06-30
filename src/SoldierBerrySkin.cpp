#include "SoldierBerrySkin.h"
#include "Menu.h"

SoldierBerrySkin::SoldierBerrySkin(Menu* menu)
{
	sf::Vector2f position = { 1020, 500 };

	setOrigin(sf::Vector2f(50, 100));
	updateSprite(position, &Resources::instance().getPlayerTexture(12));
	setscale(sf::Vector2f(100 / float(getSprite().getTexture()->getSize().x), 200 / float(getSprite().getTexture()->getSize().y)));
	updateMenu(menu);
}

void SoldierBerrySkin::execute()
{
	static sf::Sound Boom;
	Boom.setBuffer(Resources::instance().getSoundEffect(8));
	Boom.setVolume(100);
	Boom.play();

	getMenu()->getController().getPlayer().getState()->updatePrevSkin(&Resources::instance().getPlayerTexture(15));
	getMenu()->getController().getPlayer().getState()->updateCurrSkin(&Resources::instance().getPlayerTexture(15),getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition());
	getMenu()->getController().getPlayer().getState()->getCurrSkin().setScale({1,1});
	getMenu()->getController().getPlayer().getState()->getCurrSkin().setScale(sf::Vector2f(389 / (float)getMenu()->getController().getPlayer().getState()->getCurrSkin().getTexture()->getSize().x, 528 / (float)getMenu()->getController().getPlayer().getState()->getCurrSkin().getTexture()->getSize().x));

	getMenu()->getController().getPlayer().updateFallingAndDying(&Resources::instance().getPlayerTexture(14), &Resources::instance().getPlayerTexture(13));
	

	std::unique_ptr temp = std::make_unique<RunGameState>(getMenu());
	getMenu()->updateState(std::move(temp));
}

void SoldierBerrySkin::updateAnimation(bool Switch)
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
