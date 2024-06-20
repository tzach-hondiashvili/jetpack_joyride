#pragma once
#include "Pickable.h"
#include <iostream>
#include "Factory.h"
#include "Resources.h"
#include <cstdlib>
#include <ctime>   

class Coin:public Pickable
{
public:
	Coin(sf::Vector2f position);
	virtual void show();
	
private:
	static bool m_registerit;
};
