#include "ReverserState.h"
#include "Menu.h"
#include "BasicPlayerState.h"
#include "Resources.h"

ReverserState::ReverserState(const sf::Texture* currSkin, const sf::Texture* prevSkin, sf::Vector2f pos, Menu* menu)
    : m_isGravityReversed(false), m_wasSpacePressed(false), stepsPlaying(false)
{
    updateCurrSkin(currSkin, pos);
    updatePrevSkin(prevSkin);
    getCurrSkin().setScale({ 1,1 });
    updateMenu(menu);

    sf::IntRect playerRect(0, 0, getCurrSkin().getTexture()->getSize().x / 4, getCurrSkin().getTexture()->getSize().y);
    getCurrSkin().setTextureRect(playerRect);

    getCurrSkin().setOrigin(playerRect.width / 2.0f, playerRect.height / 2.0f);
    getCurrSkin().rotate(180);
    getCurrSkin().setScale({ -1,1 });

    steps.setBuffer(Resources::instance().getSoundEffect(9));
    steps.setVolume(100);
}

void ReverserState::updateAnimation(float time)
{
    static float timeSinceLastFrame = 0.f;
    timeSinceLastFrame += time;

    const float animationFrameRate = 0.3f - getCurrSkin().getPosition().x / 10000000;

    if (timeSinceLastFrame >= animationFrameRate)
    {
        setAnimationFrame((getAnimationFrame() + 1) % 4);

        int frameWidth = getCurrSkin().getTexture()->getSize().x / 4;
        sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getCurrSkin().getTexture()->getSize().y);
        getCurrSkin().setTextureRect(frameRect);

        timeSinceLastFrame = 0.f;
    }

    // Check if the player is on the ground (either floor or ceiling)
    bool isOnGround = false;

    // Get player position
    sf::Vector2f playerPosition = getCurrSkin().getPosition();

    // Define proximity ranges to floor and ceiling
    float floorLevel = 120.f;
    float ceilingLevel = 810.f;
    float proximityThreshold = 10.f; // Adjust this threshold as needed

    // Calculate proximity to floor and ceiling
    float distanceToFloor = std::abs(playerPosition.y - floorLevel);
    float distanceToCeiling = std::abs(playerPosition.y - ceilingLevel);

    // Determine if the player is close enough to either floor or ceiling
    if (distanceToFloor <= proximityThreshold || distanceToCeiling <= proximityThreshold)
    {
        isOnGround = true;
    }

    if (isOnGround)
    {
        playStepsSound();
    }
    else
    {
        stopStepsSound();
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
        getVelocity().y -= getGravity() * time;
    }
    else
    {
        getVelocity().y += getGravity() * time;
    }
}

void ReverserState::handleReverseInput()
{
    static sf::Sound reverse;

    bool isSpacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    if (!isSpacePressed && m_wasSpacePressed)
    {
        m_isGravityReversed = !m_isGravityReversed;
        getCurrSkin().rotate(180);
        getCurrSkin().setScale(m_isGravityReversed ? sf::Vector2f{ 1, 1 } : sf::Vector2f{ -1, 1 });

        if (m_isGravityReversed)
        {
            reverse.setBuffer(Resources::instance().getSoundEffect(11));
            reverse.setVolume(100);
            reverse.play();
        }
        else
        {
            reverse.setBuffer(Resources::instance().getSoundEffect(12));
            reverse.setVolume(100);
            reverse.play();
        }
    }

    m_wasSpacePressed = isSpacePressed;
}

void ReverserState::playStepsSound()
{
    if (!stepsPlaying)
    {
        steps.setLoop(true);
        steps.play();
        stepsPlaying = true;
    }
}

void ReverserState::stopStepsSound()
{
    if (stepsPlaying)
    {
        steps.stop();
        stepsPlaying = false;
    }
}
