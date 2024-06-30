#pragma once
#include "PlayerState.h"

class BasicPlayerState:public PlayerState
{
public:
	BasicPlayerState(const sf::Texture* currSkin,const sf::Texture*prevSkin,sf::Vector2f pos,Menu* menu);
	virtual ~BasicPlayerState() {};

	virtual void updateAnimation(float time) override;
	virtual void die() override;
	virtual void move(sf::Vector2f, float) override;
	virtual void print() override;

private:
	
};