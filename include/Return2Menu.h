#pragma once
#include "Command.h"
#include "Menu.h"

class Return2Menu : public Command
{
public:
	Return2Menu(Menu* menu);
	virtual void execute() override;
	virtual void updateAnimation() override {};
};