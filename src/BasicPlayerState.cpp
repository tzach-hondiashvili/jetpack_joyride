#include "BasicPlayerState.h"
#include "Menu.h"

BasicPlayerState::BasicPlayerState(sf::Texture* currSkin, sf::Texture* prevSkin, sf::Vector2f pos, Menu* menu)
{
	updateCurrSkin(currSkin, pos);
	updatePrevSkin(prevSkin);
	updateMenu(menu);

    getFlame().setPosition({ 165, 880 });
    getFlame().setTexture(Resources::instance().getObjectTexture(1));

    sf::IntRect flameRect(0, 0, getFlame().getTexture()->getSize().x / 6, getFlame().getTexture()->getSize().y);
    getFlame().setTextureRect(flameRect);
}

void BasicPlayerState::updateAnimation(float time)
{
    static int currFlame = 0;

    static float timeSinceLastFrame = 0.f;
    timeSinceLastFrame += time;

    if (timeSinceLastFrame >= 0.13f - getCurrSkin().getPosition().x / 10000000)
    {
        setAnimationFrame((getAnimationFrame() + 1) % 4);
        currFlame = (currFlame + 1) % 6;

        int frameWidth = getCurrSkin().getTexture()->getSize().x / 4;
        int flameWidth = getFlame().getTexture()->getSize().x / 6;


        if (getCurrSkin().getPosition().y != 750)
        {
            sf::IntRect frameRect(3 * frameWidth, 0, frameWidth, getCurrSkin().getTexture()->getSize().y);
            getCurrSkin().setTextureRect(frameRect);

            // Update the flame animation while the player is flying
            sf::IntRect flameRect(currFlame * flameWidth, 0, flameWidth, getFlame().getTexture()->getSize().y);
            getFlame().setTextureRect(flameRect);
        }
        else
        {

            sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getCurrSkin().getTexture()->getSize().y);
            getCurrSkin().setTextureRect(frameRect);
            currFlame = 0;
        }

        timeSinceLastFrame = 0.f;
    }
}

void BasicPlayerState::die()
{
    getMenu()->getController().getPlayer().die();
}

void BasicPlayerState::move(sf::Vector2f pos, float time)
{
    getCurrSkin().setPosition({ pos.x, getCurrSkin().getPosition().y });

    updateAnimation(time);

    applyGravity(time);
    handleInput();

    sf::Vector2f newPosition = getCurrSkin().getPosition();
    newPosition.y += getVelocity().y * time;

    // Clamp the player's position
    if (newPosition.y > 750) {
        newPosition.y = 750;
        getVelocity().y = 0;
    }
    else if (newPosition.y < 30) {
        newPosition.y = 30;
        getVelocity().y = 0;
    }
    getCurrSkin().setPosition(newPosition);
    getFlame().setPosition({newPosition.x + 15, newPosition.y + 130});
}

void BasicPlayerState::print()
{
    if (getCurrSkin().getPosition().y != 750)
    {
        getMenu()->getWindow().draw(getFlame());
    }

    getMenu()->getWindow().draw(getCurrSkin());
}

