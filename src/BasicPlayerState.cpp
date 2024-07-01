#include "BasicPlayerState.h"
#include "Menu.h"

BasicPlayerState::BasicPlayerState(const sf::Texture* currSkin, const sf::Texture* prevSkin, sf::Vector2f pos, Menu* menu)
{
	updateCurrSkin(currSkin, pos);
	updatePrevSkin(prevSkin);
	updateMenu(menu);

   getCurrSkin().setScale(sf::Vector2f((float)389 / (float)getCurrSkin().getTexture()->getSize().x, (float)528 / (float)getCurrSkin().getTexture()->getSize().x));

    getFlame().setPosition({ 165, 880 });
    getFlame().setTexture(Resources::instance().getObjectTexture(1));

    sf::IntRect playerRect(0, 0, getCurrSkin().getTexture()->getSize().x / 4, getCurrSkin().getTexture()->getSize().y);
    getCurrSkin().setTextureRect(playerRect);

    sf::IntRect flameRect(0, 0, getFlame().getTexture()->getSize().x / 6, getFlame().getTexture()->getSize().y);
    getFlame().setTextureRect(flameRect);
}

void BasicPlayerState::updateAnimation(float time)
{
    static int currFlame = 0;
    static float timeSinceLastFrame = 0.f;
    static bool stepsPlaying = false;

    static sf::Sound steps;

    if (!steps.getBuffer()) 
    {
        steps.setBuffer(Resources::instance().getSoundEffect(9));
        steps.setVolume(100);
    }

    const float animationFrameRate = 0.13f - getCurrSkin().getPosition().x / 10000000;

    timeSinceLastFrame += time;

    if (timeSinceLastFrame >= animationFrameRate)
    {
        setAnimationFrame((getAnimationFrame() + 1) % 4);
        currFlame = (currFlame + 1) % 6;

        int frameWidth = getCurrSkin().getTexture()->getSize().x / 4;
        int flameWidth = getFlame().getTexture()->getSize().x / 6;

        if (getCurrSkin().getPosition().y != 750)
        {
            if (stepsPlaying) 
            {
                steps.stop();
                stepsPlaying = false;
            }

            sf::IntRect frameRect(3 * frameWidth, 0, frameWidth, getCurrSkin().getTexture()->getSize().y);
            getCurrSkin().setTextureRect(frameRect);

            sf::IntRect flameRect(currFlame * flameWidth, 0, flameWidth, getFlame().getTexture()->getSize().y);
            getFlame().setTextureRect(flameRect);
        }
        else
        {
            if (!stepsPlaying) 
            {
                steps.setLoop(true);
                steps.play();
                stepsPlaying = true;
            }

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

    if (newPosition.y > 750) 
    {
        newPosition.y = 750;
        getVelocity().y = 0;
    }
    else if (newPosition.y < 30) 
    {
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

