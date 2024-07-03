#pragma once
#include "MenuState.h"

class RunGameState :public MenuState
{
public:
	RunGameState(Menu* menu);
	virtual ~RunGameState() override;

	virtual void update(float deltaTime) override;
	virtual void print() override;
	virtual void handleClick(const sf::Event::MouseButtonEvent& event) override;
	virtual void hoverButton(sf::Vector2i position) override;
	virtual void moveHelpLeft() override;
	virtual void moveHelpRight() override;
	sf::Sprite getBackground1();
	sf::Sprite getBackground2();
	float getScrollSpeed();
	void setScrollSpeed(float newSpeed);

	void updateOptions();
	void show();

private:
	sf::Sprite m_hall,
		m_background1,
		m_background2;

	sf::View m_view;

	std::vector<option> m_options;

	float m_scrollSpeed;

	bool m_isExplode;
};