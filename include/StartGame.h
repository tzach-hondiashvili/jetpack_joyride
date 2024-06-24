#pragma once
#include "Command.h"

class StartGame : public Command 
{
public:
	StartGame(Menu* menu);
	virtual ~StartGame() {};
	virtual void execute() override; 
	virtual void updateAnimation(bool Switch) override;
};
