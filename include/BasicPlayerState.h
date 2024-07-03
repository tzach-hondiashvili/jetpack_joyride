#pragma once
#include "PlayerState.h"
#include <SFML/Audio.hpp>

class BasicPlayerState:public PlayerState
{
public:
	BasicPlayerState(sf::Vector2f pos,Menu* menu);
	virtual ~BasicPlayerState() {};

	virtual void updateAnimation(float time) override;
	virtual void die() override;
	virtual void move(sf::Vector2f, float) override;
	virtual void print() override;

	virtual void stopSounds() override;

private:
	sf::Sound m_steps, m_engineSound;
	
};