#include "MechState.h"
#include "Menu.h"
#include "BasicPlayerState.h"

MechState::MechState(const sf::Texture* currSkin, const sf::Texture* prevSkin, sf::Vector2f pos, Menu* menu)
{
	updateCurrSkin(currSkin, pos);
	updatePrevSkin(prevSkin);
	updateMenu(menu);

	sf::IntRect playerRect(0, 0, getCurrSkin().getTexture()->getSize().x / 2, getCurrSkin().getTexture()->getSize().y);
	getCurrSkin().setTextureRect(playerRect);

    getGravity() += 400;
}

void MechState::updateAnimation(float time)
{
    static float timeSinceLastFrame = 0.f;
    timeSinceLastFrame += time;

    if (timeSinceLastFrame >= 0.3f - getCurrSkin().getPosition().x / 10000000)
    {
        if (getCurrSkin().getPosition().y != 750)
        {
            getCurrSkin().setTexture(Resources::instance().getPlayerTexture(17));
            sf::IntRect frameRect(0, 0, getCurrSkin().getTexture()->getSize().x, getCurrSkin().getTexture()->getSize().y);
            getCurrSkin().setTextureRect(frameRect);
        }
        else
        {
            setAnimationFrame((getAnimationFrame() + 1) % 2);
            getCurrSkin().setTexture(Resources::instance().getPlayerTexture(19));

            int frameWidth = getCurrSkin().getTexture()->getSize().x / 2;
            sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getCurrSkin().getTexture()->getSize().y);
            getCurrSkin().setTextureRect(frameRect);

        }

        timeSinceLastFrame = 0.f;
    }
}

void MechState::die()
{
	getMenu()->getController().getPlayer().getState() = std::move(std::make_unique<BasicPlayerState>(getPrevText(), getPrevText(), getCurrSkin().getPosition(), getMenu()));
}

void MechState::move(sf::Vector2f pos, float time)
{
    getCurrSkin().setPosition({ pos.x, getCurrSkin().getPosition().y });

    updateAnimation(time);

    applyGravity(time);
    handleInput();

    sf::Vector2f newPosition = getCurrSkin().getPosition();
    newPosition.y += getVelocity().y * time;

    // Clamp the player's position
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
}

void MechState::print()
{
	getMenu()->getWindow().draw(getCurrSkin());
}
