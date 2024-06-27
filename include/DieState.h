#pragma once
#include "MenuState.h"


class DieState :public MenuState
{

public:
	DieState(Menu* menu,sf::Sprite& bg1, sf::Sprite& bg2);

	virtual ~DieState()override {};

	virtual void update(float deltaTime) override;
	virtual void print() override;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event) override;

	virtual void moveHelpLeft()	override {};
	virtual void moveHelpRight() override {};

	virtual void hoverButton(sf::Vector2i ) override;

	void updateOptions();
	void show();

private:
	std::vector<option> m_Buttons;

	sf::Sprite m_backGround1;
	sf::Sprite m_backGround2;

	bool m_onGround;

};