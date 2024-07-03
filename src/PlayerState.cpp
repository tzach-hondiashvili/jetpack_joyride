#include "PlayerState.h"
#include "Menu.h"

PlayerState::PlayerState()
	:m_currSkin(sf::Sprite()), m_Flame(sf::Sprite()),m_menu(nullptr),m_animationFrame(0), m_velocity(0.f, 0.f), m_gravity(1200.f), m_jumpForce(-400.f)
{
}

void PlayerState::updateCurrSkin(const sf::Texture* currSkin, sf::Vector2f pos)
{
	m_currSkin.setTexture(*currSkin);
	m_currSkin.setPosition(pos);
}



void PlayerState::updateMenu(Menu* Menu)
{
	m_menu = Menu;
}

void PlayerState::setAnimationFrame(int frame)
{
	m_animationFrame = frame;
}

void PlayerState::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
	{
		m_velocity.y = m_jumpForce;
	}
}

int PlayerState::getAnimationFrame()
{
	return m_animationFrame;
}

sf::Sprite& PlayerState::getCurrSkin()
{
	return m_currSkin;
}

sf::Sprite& PlayerState::getFlame()
{
	return m_Flame;
}

sf::Vector2f& PlayerState::getVelocity()
{
	return m_velocity;
}

Menu* PlayerState::getMenu()
{
	return m_menu;
}

float& PlayerState::getGravity()
{
	return m_gravity;
}

float& PlayerState::getJumpForce()
{
	return m_jumpForce;
}

void PlayerState::applyGravity(float deltaTime)
{
	if (!(m_currSkin.getPosition().y == 750))
	{
		m_velocity.y += m_gravity * deltaTime;
	}
}
