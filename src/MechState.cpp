#include "MechState.h"
#include "Menu.h"
#include "BasicPlayerState.h"

MechState::MechState(const sf::Texture* currSkin, const sf::Texture* prevSkin, sf::Vector2f pos, Menu* menu)
{
	updateCurrSkin(currSkin, pos);
	updatePrevSkin(prevSkin);
    getCurrSkin().setScale({ 1,1 });
	updateMenu(menu);

	sf::IntRect playerRect(0, 0, getCurrSkin().getTexture()->getSize().x / 2, getCurrSkin().getTexture()->getSize().y);
	getCurrSkin().setTextureRect(playerRect);

    getGravity() += 400;
}

void MechState::updateAnimation(float time)
{
    static float timeSinceLastFrame = 0.f;
    static bool runPlaying = false;

    if (!run.getBuffer()) 
    {
        run.setBuffer(Resources::instance().getSoundEffect(10));
        run.setVolume(100);
    }

    timeSinceLastFrame += time;

    const float animationFrameRate = 0.3f - getCurrSkin().getPosition().x / 10000000;

    if (timeSinceLastFrame >= animationFrameRate)
    {
        if (getCurrSkin().getPosition().y != 750)
        {
            // Not on the ground
            getCurrSkin().setTexture(Resources::instance().getPlayerTexture(17));
            sf::IntRect frameRect(0, 0, getCurrSkin().getTexture()->getSize().x, getCurrSkin().getTexture()->getSize().y);
            getCurrSkin().setTextureRect(frameRect);

            if (runPlaying) {
                run.stop();
                runPlaying = false;
            }
        }
        else
        {
            // On the ground
            setAnimationFrame((getAnimationFrame() + 1) % 2);
            getCurrSkin().setTexture(Resources::instance().getPlayerTexture(19));

            int frameWidth = getCurrSkin().getTexture()->getSize().x / 2;
            sf::IntRect frameRect(getAnimationFrame() * frameWidth, 0, frameWidth, getCurrSkin().getTexture()->getSize().y);
            getCurrSkin().setTextureRect(frameRect);

            if (!runPlaying) 
            {
                run.setLoop(true); 
                run.play();
                runPlaying = true;
            }
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
