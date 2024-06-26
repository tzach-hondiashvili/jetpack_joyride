#pragma once
#include "Command.h"

class Quit : public Command
{
public:
	Quit(Menu* menu);
	virtual ~Quit() {};

	virtual void execute() override;
	virtual void updateAnimation(bool ) override {};
};