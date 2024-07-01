#pragma once
#include "PlayerState.h"
#include <SFML/Audio.hpp>

class ReverserState : public PlayerState
{
public:
    ReverserState(const sf::Texture* currSkin, const sf::Texture* prevSkin, sf::Vector2f pos, Menu* menu);
    virtual ~ReverserState() {};

    virtual void updateAnimation(float time) override;
    virtual void die() override;
    virtual void move(sf::Vector2f pos, float time) override;
    virtual void print() override;

    void applyReverseGravity(float time);
    void handleReverseInput();

private:
    bool m_isGravityReversed;
    bool m_wasSpacePressed;

    sf::Sound steps;
    bool stepsPlaying;

    void playStepsSound();
    void stopStepsSound();
};
