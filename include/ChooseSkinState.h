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
	virtual void moveHelpLeft()	override {};
	virtual void moveHelpRight() override {};

private:
	std::vector<option> m_skins;
	sf::Sprite m_backGround;
	sf::Text m_ChooseSkin;
};