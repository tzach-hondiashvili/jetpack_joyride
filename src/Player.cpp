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

    /*sf::IntRect playerRect(0, 0, getSprite().getTexture()->getSize().x / 4, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(playerRect);*/

    //m_flame.setPosition({ 165, 880 });
    //m_flame.setTexture(Resources::instance().getObjectTexture(1));

    //sf::IntRect flameRect(0, 0, m_flame.getTexture()->getSize().x / 6, m_flame.getTexture()->getSize().y);
    //m_flame.setTextureRect(flameRect);

    m_state = std::move(std::make_unique<BasicPlayerState>(getSprite().getTexture(), getSprite().getTexture(), getSprite().getPosition(), menu));

}

void Player::updateAnimation(float time)
{
    static int currFlame = 0;
    
    static float timeSinceLastFrame = 0.f;
    timeSinceLastFrame += time;

    if (timeSinceLastFrame >= 0.13f - getState()->getCurrSkin().getPosition().x / 10000000)
    {
        getState()->setAnimationFrame((getState()->getAnimationFrame() + 1) % 4);
        currFlame = (currFlame + 1) % 6;

        int frameWidth = getState()->getCurrSkin().getTexture()->getSize().x / 4;
        int flameWidth = getState()->getFlame().getTexture()->getSize().x / 6;


        if (getState()->getCurrSkin().getPosition().y != 750)
        {
            sf::IntRect frameRect(3 * frameWidth, 0, frameWidth, getState()->getCurrSkin().getTexture()->getSize().y);
            getState()->getCurrSkin().setTextureRect(frameRect);

            // Update the flame animation while the player is flying
            sf::IntRect flameRect(currFlame * flameWidth, 0, flameWidth, getState()->getFlame().getTexture()->getSize().y);
            getState()->getFlame().setTextureRect(flameRect);
        }
        else
        {

            sf::IntRect frameRect(getState()->getAnimationFrame() * frameWidth, 0, frameWidth, getState()->getCurrSkin().getTexture()->getSize().y);
            getState()->getCurrSkin().setTextureRect(frameRect);
            currFlame = 0;
        }

        timeSinceLastFrame = 0.f;
    }
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

