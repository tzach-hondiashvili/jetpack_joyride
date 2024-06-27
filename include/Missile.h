#pragma once
#include "Enemy.h"


class Missile :public Enemy
{
public:
	Missile(sf::Vector2f position);
	virtual ~Missile() override {};
	void move(sf::Vector2f pos, float time) override;
	virtual void show();
	virtual void updateAnimation(float ) override;
	void updatebeforeMissile(int index);
	virtual void updateSoundAndWarnings(sf::Vector2f pos) override;
	virtual sf::Sprite getWarning() override;
	void updateWarningLocation(sf::Vector2f pos);

private:
	static bool m_registerit;
	sf::Sprite m_beforeMissile;
};