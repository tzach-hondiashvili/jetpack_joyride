#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player()
    : m_lives(1), m_velocity(0.f, 0.f), m_gravity(1200.f), m_jumpForce(-400.f), m_isFlying(false), m_flame(sf::Sprite()),m_coinsCounter(0)
{
}

int Player::getLives() const {
    return m_lives;
}

sf::Sprite& Player::getFlame()
{
    return m_flame;
}

void Player::applyGravity(float deltaTime)
{
    if (!m_isFlying)
    {
        m_velocity.y += m_gravity * deltaTime;
    }
}

void Player::move(sf::Vector2f pos, float time)
{
    updateSpritePos({ pos.x, getSprite().getPosition().y });

    updateAnimation(time);

    applyGravity(time);
    handleInput();

    sf::Vector2f newPosition = getSprite().getPosition();
    newPosition.y += m_velocity.y * time;

    // Clamp the player's position
    if (newPosition.y > 750) {
        newPosition.y = 750;
        m_velocity.y = 0;
    }
    else if (newPosition.y < 30) {
        newPosition.y = 30;
        m_velocity.y = 0;
    }
    updateSpritePos(newPosition);
    m_flame.setPosition({ newPosition.x + 15, newPosition.y + 130 });
}

void Player::createPlayer()
{
    updateSprite({ 150, 750 }, &Resources::instance().getPlayerTexture(7));

    sf::IntRect playerRect(0, 0, getSprite().getTexture()->getSize().x / 4, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(playerRect);

    m_flame.setPosition({ 165, 880 });
    m_flame.setTexture(Resources::instance().getObjectTexture(1));

    sf::IntRect flameRect(0, 0, m_flame.getTexture()->getSize().x / 6, m_flame.getTexture()->getSize().y);
    m_flame.setTextureRect(flameRect);
}

bool Player::isFlying() {
    return m_isFlying;
}

void Player::handleInput()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_velocity.y = m_jumpForce;
        m_isFlying = true;
    }
    else {
        m_isFlying = false;
    }
}

void Player::updateAnimation(float time)
{
    static int currFlame = 0;
    
    static float timeSinceLastFrame = 0.f;
    timeSinceLastFrame += time;

    if (timeSinceLastFrame >= 0.13f - getSprite().getPosition().x/10000000)
    {
        setAnimationFrame((getAnimationFrame() + 1) % 4);
        currFlame = (currFlame + 1) % 6;

        int frameWidth = getSprite().getTexture()->getSize().x / 4;
        int flameWidth = m_flame.getTexture()->getSize().x / 6;


        if (getSprite().getPosition().y != 750)
        {
            sf::IntRect frameRect(3 * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
            changeSpriteAnimation(frameRect);

            // Update the flame animation while the player is flying
            sf::IntRect flameRect(currFlame * flameWidth, 0, flameWidth, getSprite().getTexture()->getSize().y);
            m_flame.setTextureRect(flameRect);
        }
        else
        {

            sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getSprite().getTexture()->getSize().y);
            changeSpriteAnimation(frameRect);
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

Player::Player(Player&& other) noexcept
    : MovingObjects(std::move(other)),
    m_lives(other.m_lives),
    m_coinsCounter(other.m_coinsCounter),
    m_velocity(std::move(other.m_velocity)),
    m_gravity(other.m_gravity),
    m_jumpForce(other.m_jumpForce),
    m_isFlying(other.m_isFlying),
    m_flame(std::move(other.m_flame))
{
    other.m_lives = 0;
    other.m_coinsCounter = 0;
    other.m_velocity = sf::Vector2f(0, 0);
    other.m_gravity = 0.0f;
    other.m_jumpForce = 0.0f;
    other.m_isFlying = false;
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
    sf::Vector2f newPosition = getSprite().getPosition();

     m_velocity.y += m_gravity * time;
 
    // Clamp the player's position
    if (newPosition.y > 750) 
    {
        newPosition.y = 750;
        m_velocity.y = 0;
        m_velocity.x = 0;
    }
    else
    {
        newPosition.y += m_velocity.y * time;
        newPosition.x += 200 * time;
    }

    updateSpritePos(newPosition);

}

