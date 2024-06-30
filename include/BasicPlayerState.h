#pragma once
#include "PlayerState.h"

class BasicPlayerState:public PlayerState
{
public:
	BasicPlayerState(sf::Texture* currSkin,sf::Texture*prevSkin,sf::Vector2f pos,Menu* menu);
	virtual ~BasicPlayerState() {};

	virtual void updateAnimation(float time) override;
	virtual void die() override;
	virtual void move(sf::Vector2f, float) override;
	virtual void print();

private:
	
};