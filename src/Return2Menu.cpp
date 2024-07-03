#include "Return2Menu.h"
#include "Menu.h"

Return2Menu::Return2Menu(Menu* menu)
{
	updateMenu(menu);
	sf::Vector2f position = { 23, 30 };

	updateSprite(position, &Resources::instance().getOtherTexture(0));
	
}
void Return2Menu::execute()
{
	getMenu()->getController().getPlayer().getState()->stopSounds();
	static sf::Sound Click;
	Click.setBuffer(Resources::instance().getSoundEffect(7));
	Click.setVolume(100);
	Click.play();

	Resources::instance().endGameMusic();
	Resources::instance().startMenuMusic();
	getMenu()->resetView();
	getMenu()->getController().getPlayer().resetCoins();
	getMenu()->getController().getMap().resetMap();
	getMenu()->updateState(std::move(std::make_unique<DefaultMenu>(getMenu())));
}
