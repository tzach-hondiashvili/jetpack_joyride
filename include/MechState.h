#pragma once
#include "PlayerState.h"
#include <SFML/Audio.hpp>

class MechState:public PlayerState
{
public:
	MechState(sf::Vector2f pos, Menu* menu);
	virtual ~MechState() {};

	virtual void updateAnimation(float time) override;
	virtual void die() override;
	virtual void move(sf::Vector2f, float) override;
	virtual void print() override;
	virtual void stopSounds() override;
private:
	sf::Sound m_run, m_engineSound;
};