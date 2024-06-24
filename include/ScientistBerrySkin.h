#pragma once
#include "Command.h"
#include "Menu.h"

class ScientistBerrySkin : public Command
{
public:
	ScientistBerrySkin(Menu* menu);
	virtual ~ScientistBerrySkin() {};

	virtual void execute() override;
	virtual void updateAnimation(bool Switch) override;
};