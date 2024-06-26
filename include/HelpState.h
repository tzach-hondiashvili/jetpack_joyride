#pragma once
#include "MenuState.h"

class HelpState :public MenuState
{
public:
	HelpState(Menu* menu);

	virtual ~HelpState()override {};

	virtual void update(float ) override;
	virtual void print() override;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event) override;

	virtual void moveHelpLeft()	override;
	virtual void moveHelpRight() override;

	virtual void hoverButton(sf::Vector2i ) override;

private:
	std::vector<option> m_helpButtons;
	sf::Sprite m_backGround;
	unsigned m_helpPage;

};