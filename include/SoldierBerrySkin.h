#pragma once
#include "Command.h"
#include "Menu.h"

class SoldierBerrySkin : public Command
{
public:
	SoldierBerrySkin(Menu* menu);
	virtual void execute() override;
	virtual void updateAnimation(bool Switch) override;
};