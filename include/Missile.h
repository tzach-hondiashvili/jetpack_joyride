#pragma once
#include "Enemy.h"
#include "Factory.h"

class Missile :public Enemy
{
public:
	Missile(sf::Vector2f position);
	virtual ~Missile() override {};
	void move(sf::Vector2f pos, float time) override;
	virtual void show();
	virtual void updateAnimation(float ) override;
	void updatebeforeMissile(int index);
	bool getIsPlayed();
	virtual void updateSoundAndWarnings(sf::Vector2f pos) override;
private:
	static bool m_registerit;
	sf::Texture *m_beforeMissile;
};