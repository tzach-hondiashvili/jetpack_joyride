#pragma once
#include "Pickable.h"

class PowerUp:public Pickable
{
public:
	PowerUp(sf::Vector2f position);
	virtual ~PowerUp() override {};

private:
	static bool m_registerit;
};