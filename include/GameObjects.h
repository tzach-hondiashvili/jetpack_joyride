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
	void updateSprite(sf::Vector2f position, sf::Texture* texture);
	void updateSpritePos(sf::Vector2f position);
private:
	sf::Sprite m_sprite;
};