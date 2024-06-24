#pragma once
#include "Command.h"
#include "Menu.h"

class KingSkinOption : public Command
{
public:
	KingSkinOption(Menu* menu);
	virtual ~KingSkinOption() {};

	virtual void execute() override;
	virtual void updateAnimation(bool Switch) override;
};