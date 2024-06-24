#pragma once
#include "Command.h"

class HelpRight : public Command
{
public:
	HelpRight(Menu* menu);
	virtual ~HelpRight() {};

	virtual void execute() override;
	virtual void updateAnimation(bool Switch) override {};
};
