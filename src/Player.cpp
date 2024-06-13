#include "Player.h"
#include <SFML/Window/Keyboard.hpp>

Player::Player()
    : m_lives(1), m_velocity(0.f, 0.f), m_gravity(1000.f), m_jumpForce(-500.f), m_isFlying(false) {
}

int Player::getLives() const {
    return m_lives;
}

void Player::applyGravity(float deltaTime) {
    if (!m_isFlying) {
        m_velocity.y += m_gravity * deltaTime;
    }
}

void Player::move(sf::Vector2f pos, float time) {
    static int currFrame = 0;
    updateSpritePos({ pos.x, getSprite().getPosition().y });

    static float timeSinceLastFrame = 0.f;
    timeSinceLastFrame += time;

    if (timeSinceLastFrame >= 0.18f) {
        currFrame = (currFrame + 1) % 4;

        int frameWidth = getSprite().getTexture()->getSize().x / 4; // Assuming 4 frames in the texture width
        if (getSprite().getPosition().y != 750)
        {
            sf::IntRect frameRect(3 * frameWidth, 0, frameWidth, getSprite().getTextureRect().height);
            changeSpriteAnimation(frameRect);
        }
        else
        {
            sf::IntRect frameRect(currFrame * frameWidth, 0, frameWidth, getSprite().getTextureRect().height);
            changeSpriteAnimation(frameRect);
        }


        timeSinceLastFrame = 0.f;
    }

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
}

void Player::createPlayer() {
    updateSprite({ 150, 750 }, &Resources::instance().getPlayerTexture(7));

    sf::IntRect rect(0, 0, getSprite().getTexture()->getSize().x / 4, getSprite().getTexture()->getSize().y);
    changeSpriteAnimation(rect);
}

bool Player::isFlying() {
    return m_isFlying;
}

void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        m_velocity.y = m_jumpForce;
        m_isFlying = true;
    }
    else {
        m_isFlying = false;
    }
}
