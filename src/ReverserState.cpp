#include "ReverserState.h"
#include "Menu.h"
#include "BasicPlayerState.h"

ReverserState::ReverserState(const sf::Texture* currSkin, const sf::Texture* prevSkin, sf::Vector2f pos, Menu* menu)
    :m_isGravityReversed(false),m_wasSpacePressed(false)
{
    updateCurrSkin(currSkin, pos);
    updatePrevSkin(prevSkin);
    updateMenu(menu);

    sf::IntRect playerRect(0, 0, getCurrSkin().getTexture()->getSize().x / 4, getCurrSkin().getTexture()->getSize().y);
    getCurrSkin().setTextureRect(playerRect);

    getCurrSkin().setOrigin(playerRect.width / 2.0f, playerRect.height / 2.0f);
    getCurrSkin().rotate(180);
    getCurrSkin().setScale({-1,1});

}

void ReverserState::updateAnimation(float time)
{
    static float timeSinceLastFrame = 0.f;
    timeSinceLastFrame += time;

    if (timeSinceLastFrame >= 0.3f - getCurrSkin().getPosition().x / 10000000)
    {
        setAnimationFrame((getAnimationFrame() + 1) % 4);

        int frameWidth = getCurrSkin().getTexture()->getSize().x / 4;
        sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getCurrSkin().getTexture()->getSize().y);
        getCurrSkin().setTextureRect(frameRect);

        timeSinceLastFrame = 0.f;
    }
}

void ReverserState::die()
{
    getMenu()->getController().getPlayer().getState() = std::move(std::make_unique<BasicPlayerState>(getPrevText(), getPrevText(), getCurrSkin().getPosition(), getMenu()));
}

void ReverserState::move(sf::Vector2f pos, float time)
{
    getCurrSkin().setPosition({ pos.x, getCurrSkin().getPosition().y });

    updateAnimation(time);

    applyReverseGravity(time);
    handleReverseInput();

    sf::Vector2f newPosition = getCurrSkin().getPosition();
    newPosition.y += getVelocity().y * time;

    // Clamp the player's position
    if (m_isGravityReversed)
    {
        if (newPosition.y < 120)
        {
            newPosition.y = 120;
            getVelocity().y = 0;
        }
        else if (newPosition.y > 810)
        {
            newPosition.y = 810;
            getVelocity().y = 0;
        }
    }
    else
    {
        if (newPosition.y > 810)
        {
            newPosition.y = 810;
            getVelocity().y = 0;
        }
        else if (newPosition.y < 120)
        {
            newPosition.y = 120;
            getVelocity().y = 0;
        }
    }
    getCurrSkin().setPosition(newPosition);
}

void ReverserState::print()
{
    getMenu()->getWindow().draw(getCurrSkin());
}

void ReverserState::applyReverseGravity(float time)
{
    if (m_isGravityReversed) 
    {
        getVelocity().y -= getGravity() * time; // Apply gravity upwards
    }
    else 
    {
        getVelocity().y += getGravity() * time; // Apply gravity downwards
    }
}

void ReverserState::handleReverseInput()
{
    bool isSpacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    if (!isSpacePressed && m_wasSpacePressed)
    {
        m_isGravityReversed = !m_isGravityReversed;
        getCurrSkin().rotate(180);
        getCurrSkin().setScale(m_isGravityReversed ? sf::Vector2f{ 1, 1 } : sf::Vector2f{ -1, 1 });
    }


    m_wasSpacePressed = isSpacePressed;
}
