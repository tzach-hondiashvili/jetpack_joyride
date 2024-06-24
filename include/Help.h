#pragma once
#include "Command.h"
#include "Menu.h"

class Help : public Command
{
public:
	Help(Menu * menu);
	virtual ~Help() {};

	virtual void execute() override;
	virtual void updateAnimation(bool Switch) override;
};