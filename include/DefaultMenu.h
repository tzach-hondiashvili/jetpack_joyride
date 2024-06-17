#pragma once
#include "MenuState.h"
#include "Menu.h"

class DefaultMenu :public MenuState
{
public:
	DefaultMenu(Menu* menu);

	virtual ~DefaultMenu() override {};

	virtual void update(float deltaTime) override;
	virtual void print() override;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event) override;
	virtual void hoverButton(sf::Vector2i position) override;
	virtual void moveHelpLeft() override;
	virtual void moveHelpRight() override;

	void updateOptions();
	void show();

private:
	std::vector<option> m_options;
};