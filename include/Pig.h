#pragma once
#include "Pickable.h"

class Pig :public Pickable
{
public:
	Pig(sf::Vector2f position);
	virtual ~Pig() override {};

private:
	static bool m_registerit;
};