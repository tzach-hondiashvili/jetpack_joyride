#pragma once
#include "Command.h"
#include "Menu.h"

class Return2Menu : public Command
{
public:
	Return2Menu(Menu* menu);
	virtual ~Return2Menu() {};

	virtual void execute() override;
	virtual void updateAnimation(bool ) override {};
};