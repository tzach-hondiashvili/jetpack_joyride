#pragma once
#include "Command.h"

class Quit : public Command
{
public:
	Quit(Menu* menu);
	virtual void execute() override;
	virtual void updateAnimation() override {};
};