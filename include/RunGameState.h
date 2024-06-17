#pragma once
#include "MenuState.h"

class RunGameState :public MenuState
{
public:
	RunGameState(Menu* menu);

	virtual void update(float deltaTime) override;
	virtual void print() override;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event) override;
	virtual void hoverButton(sf::Vector2i position) override;
	virtual void moveHelpLeft() override;
	virtual void moveHelpRight() override;

private:
	sf::Sprite m_hall,
		m_background1,
		m_background2;

	sf::View m_view;

	float m_scrollSpeed;
};