#pragma once
#include "Pickable.h"

class SpeedBoost :public Pickable
{
public:
	SpeedBoost(sf::Vector2f position);
	virtual ~SpeedBoost() override {};

private:
	static bool m_registerit;
};