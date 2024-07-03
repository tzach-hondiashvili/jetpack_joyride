#pragma once
#include <SFML/Graphics.hpp>

//forward decleration 
class Menu;

class PlayerState
{
public:
	PlayerState();
	virtual ~PlayerState() {};
	virtual void updateAnimation(float time) = 0;
	virtual void die() = 0;

	void updateCurrSkin(const sf::Texture* currSkin,sf::Vector2f pos);

	void updateMenu(Menu* Menu);
	void setAnimationFrame(int frame);
	void handleInput();

	int getAnimationFrame();
	sf::Sprite& getCurrSkin();
	sf::Sprite& getFlame();
	sf::Vector2f& getVelocity();
	Menu* getMenu();
	float& getGravity();
	float& getJumpForce();

	virtual void move(sf::Vector2f , float ) = 0;
	virtual void print() = 0;
	virtual void stopSounds() = 0;

	void applyGravity(float deltaTime);

private:
	Menu* m_menu;
	sf::Sprite m_currSkin, m_Flame;

	int m_animationFrame;

	sf::Vector2f m_velocity;
	float m_gravity;
	float m_jumpForce;
};