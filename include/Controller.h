#pragma once
#include "map.h"
#include "Player.h"

class Controller
{
public:
	Controller();

private:
	Player m_player;
	Map m_map;
};