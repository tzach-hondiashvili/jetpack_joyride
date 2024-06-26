#pragma once
#include "MovingObjects.h"

class Player : public MovingObjects {
public:
    Player();
    virtual ~Player() override{};

    int getLives() const;
    sf::Sprite& getFlame();
    virtual void move(sf::Vector2f pos, float time);
    virtual void show() override {} ;
    void createPlayer();
    bool isFlying();
    void handleInput();
    virtual void updateAnimation(float time) override;
    void collectCoin();
    int getCoinsCounter();
    void resetCoins();
    Player(Player&& other) noexcept;
    void die();


private:
    int m_lives;
    int m_coinsCounter;
    sf::Vector2f m_velocity;
    float m_gravity;
    float m_jumpForce;
    bool m_isFlying;
    void applyGravity(float deltaTime);
    sf::Sprite m_flame;
};
