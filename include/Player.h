#pragma once
#include "MovingObjects.h"
#include "PlayerState.h"

class Player : public MovingObjects {
public:
    Player();
    virtual ~Player() override {};

    int getLives() const;

    virtual void move(sf::Vector2f , float ) {};
    virtual void show() override {};
    virtual void updateAnimation(float) {};

    void createPlayer(Menu* menu);
    
    void collectCoin();
    int getCoinsCounter();
    void resetCoins();
    void die();
    void updateFallingAndDying(sf::Texture* falling, sf::Texture* dying);

    sf::Texture* getFallingTexture();
    sf::Texture* getDyingTexture();
    void fall(float time);

    std::unique_ptr<PlayerState>& getState();


private:
    int m_lives;
    int m_coinsCounter;

    sf::Sprite m_flame;
    sf::Texture* m_falling,* m_dying;

    std::unique_ptr<PlayerState> m_state;
};
