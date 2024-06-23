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
	virtual void show() {};
	void setScale(sf::Vector2f scale);
	virtual void updateAnimation(float time) = 0;
	int getAnimationFrame();
	void setAnimationFrame(int frame);

private:
	sf::Sprite m_sprite;
	int m_animationFrame;
};