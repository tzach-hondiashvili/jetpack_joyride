#pragma once
#include "MovingObjects.h"
#include <iostream>
#include "Factory.h"
#include "Resources.h"
#include <cstdlib>
#include <ctime>   

class Scientist :public MovingObjects
{
public:
	Scientist(sf::Vector2f position);
	virtual ~Scientist() override {};
	virtual void move(sf::Vector2f pos, float time) override;
	virtual void show();
	virtual void updateAnimation(float) override;

private:
	static bool m_registerit;
	bool m_isLeft;
};
