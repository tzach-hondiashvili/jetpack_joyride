#pragma once
#include "PlayerState.h"

class MechState:public PlayerState
{
public:
	MechState(const sf::Texture* currSkin, const sf::Texture* prevSkin, sf::Vector2f pos, Menu* menu);
	virtual ~MechState() {};

	virtual void updateAnimation(float time) override;
	virtual void die() override;
	virtual void move(sf::Vector2f, float) override;
	virtual void print() override;
private:

};