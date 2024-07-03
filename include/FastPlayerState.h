#pragma once
#include "PlayerState.h"
#include <SFML/Audio.hpp>

class FastPlayerState :public PlayerState
{
public:
	FastPlayerState(sf::Vector2f pos, Menu* menu);
	virtual ~FastPlayerState() {};

	virtual void updateAnimation(float time) {};
	virtual void die() {};
	virtual void move(sf::Vector2f, float time) override;
	virtual void print() override;

	virtual void stopSounds() {};

private:
	float m_timeInState;
};