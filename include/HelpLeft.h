#pragma once
#include "Command.h"

class HelpLeft : public Command
{
public:
	HelpLeft(Menu* menu);
	virtual ~HelpLeft() {};

	virtual void execute() override;
	virtual void updateAnimation(bool Switch) override {};
};
