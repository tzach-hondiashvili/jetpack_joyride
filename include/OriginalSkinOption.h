#pragma once
#include "Command.h"
#include "Menu.h"

class OriginalSkinOption : public Command
{
public:
	OriginalSkinOption(Menu* menu);
	virtual ~OriginalSkinOption() {};

	virtual void execute() override;
	virtual void updateAnimation(bool Switch) override;
};