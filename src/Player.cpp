#include "Player.h"
#include <SFML/Window/Keyboard.hpp>
#include "BasicPlayerState.h"

Player::Player()
    : m_lives(1),m_coinsCounter(0),m_dying(nullptr),m_falling(nullptr)
{
}

int Player::getLives() const 
{
    return m_lives;
}


void Player::createPlayer(Menu* menu)
{
    updateSprite({ 150, 750 }, &Resources::instance().getPlayerTexture(7));

    m_state = std::move(std::make_unique<BasicPlayerState>(getSprite().getTexture(), getSprite().getTexture(), getSprite().getPosition(), menu));

}

void Player::collectCoin()
{
    m_coinsCounter += 1;
}

int Player::getCoinsCounter()
{
    return m_coinsCounter;
}

void Player::resetCoins()
{
    m_lives = 1;
    m_coinsCounter = 0;
}

void Player::die()
{
    m_lives = 0;
}

void Player::updateFallingAndDying(sf::Texture* falling, sf::Texture* dying)
{
    m_falling = falling;
    m_dying = dying;
}

sf::Texture* Player::getFallingTexture()
{
    return m_falling;
}

sf::Texture* Player::getDyingTexture()
{
    return m_dying;
}

void Player::fall(float time)
{
    sf::Vector2f newPosition = getState()->getCurrSkin().getPosition();

    getState()->getVelocity().y += getState()->getGravity() * time;
 
    // Clamp the player's position
    if (newPosition.y >= 750) 
    {
        newPosition.y = 750;
        getState()->getVelocity().y = 0;
    }
    else
    {
        newPosition.y += getState()->getVelocity().y * time;
        newPosition.x += 200 * time;
    }

    getState()->getCurrSkin().setPosition(newPosition);
}

std::unique_ptr<PlayerState>& Player::getState()
{
    return m_state;
}

