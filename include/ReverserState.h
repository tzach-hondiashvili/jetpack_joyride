#pragma once
#include "PlayerState.h"
#include <SFML/Audio.hpp>

class ReverserState : public PlayerState
{
public:
    ReverserState(sf::Vector2f pos, Menu* menu);
    virtual ~ReverserState() {};

    virtual void updateAnimation(float time) override;
    virtual void die() override;
    virtual void move(sf::Vector2f pos, float time) override;
    virtual void print() override;

    void applyReverseGravity(float time);
    void handleReverseInput();

    virtual void stopSounds() override;

private:
    bool m_isGravityReversed;
    bool m_wasSpacePressed;

    sf::Sound m_steps;
    bool m_stepsPlaying;

    void playStepsSound();
    void stopStepsSound();
};
