#pragma once
#include "MenuState.h"

class ChooseSkinState :public MenuState
{
public:
	ChooseSkinState(Menu* menu);

	virtual ~ChooseSkinState()override {};

	virtual void update(float deltaTime) override;
	virtual void print() override;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event) override;


	virtual void hoverButton(sf::Vector2i position) override;

private:

};