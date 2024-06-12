#include "Controller.h"

Controller::Controller()
	:m_map({})
{

}

Player& Controller::getPlayer()
{
	return m_player;
}
