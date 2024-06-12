#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class GameObjects 
{
public:
	GameObjects();
	GameObjects(sf::Vector2f position, sf::Texture* texture);
	const sf::Sprite &getSprite() const;
	void changeSpriteAnimation(sf::IntRect rect);
private:
	sf::Sprite m_sprite;
};