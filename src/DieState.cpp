#include "DieState.h"
#include "Menu.h"
#include "Return2Menu.h"
#include "StartGame.h"

DieState::DieState(Menu* menu, sf::Sprite& bg1, sf::Sprite& bg2)
    : m_backGround1(std::move(bg1)),
    m_backGround2(std::move(bg2)), m_onGround(false)
{
    updateMenu(menu);

    auto& player = getMenu()->getController().getPlayer().getState();
    player->updateCurrSkin(getMenu()->getController().getPlayer().getFallingTexture(), player->getCurrSkin().getPosition());

    // Calculate scale factors based on desired size
    float scaleX = (450.0f / 2) / player->getCurrSkin().getTexture()->getSize().x;
    float scaleY = 150.0f / player->getCurrSkin().getTexture()->getSize().y;
    player->getCurrSkin().setScale(sf::Vector2f(scaleX, scaleY));

    // Initialize player's animation for falling state
    sf::IntRect playerRect(0, 0, player->getCurrSkin().getTexture()->getSize().x / 4, player->getCurrSkin().getTexture()->getSize().y);
    player->getCurrSkin().setTextureRect(playerRect);
    player->setAnimationFrame(0);

    updateOptions();
}

void DieState::update(float deltaTime)
{
    static float timeSinceLastFrame = 0.f;
    timeSinceLastFrame += deltaTime;

    getMenu()->getController().getPlayer().fall(deltaTime);

    if (timeSinceLastFrame >= 0.35f)
    {
        if (getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition().y == 750)
        {
            if (!m_onGround)
            {
                getMenu()->getController().getPlayer().getState()->updateCurrSkin(getMenu()->getController().getPlayer().getDyingTexture(), getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition());
                sf::IntRect playerRect(0, 0, getMenu()->getController().getPlayer().getState()->getCurrSkin().getTexture()->getSize().x, getMenu()->getController().getPlayer().getState()->getCurrSkin().getTexture()->getSize().y);
                getMenu()->getController().getPlayer().getState()->getCurrSkin().setTextureRect(playerRect);

                static sf::Sound HitFloor;
                HitFloor.setBuffer(Resources::instance().getSoundEffect(2));
                HitFloor.setVolume(100);
                HitFloor.play();
                m_onGround = true;
            }
            getMenu()->getController().getPlayer().getState()->getCurrSkin().setPosition(getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition() + sf::Vector2f(0, 70));
        }
        else
        {
            getMenu()->getController().getPlayer().getState()->setAnimationFrame((getMenu()->getController().getPlayer().getAnimationFrame() + 1));

            if (getMenu()->getController().getPlayer().getState()->getAnimationFrame() < 5)
            {
                int frameWidth = getMenu()->getController().getPlayer().getState()->getCurrSkin().getTexture()->getSize().x / 4;

                sf::IntRect frameRect(frameWidth, 0, frameWidth, getMenu()->getController().getPlayer().getState()->getCurrSkin().getTexture()->getSize().y);
                getMenu()->getController().getPlayer().getState()->getCurrSkin().setTextureRect(frameRect);
            }

            timeSinceLastFrame = 0.f;
        }
    }   
}

void DieState::print()
{
    getMenu()->getWindow().draw(m_backGround1);
    getMenu()->getWindow().draw(m_backGround2);

    for (auto it = getMenu()->getController().getMap().getPickables().begin(); it != getMenu()->getController().getMap().getPickables().end(); it++)
    {
        getMenu()->getWindow().draw((*it)->getSprite());
    }
    for (auto it = getMenu()->getController().getMap().getObstacles().begin(); it != getMenu()->getController().getMap().getObstacles().end(); it++)
    {
        getMenu()->getWindow().draw((*it)->getSprite());
    }
    for (auto it = getMenu()->getController().getMap().getEnemies().begin(); it != getMenu()->getController().getMap().getEnemies().end(); it++)
    {
        getMenu()->getWindow().draw((*it)->getSprite());
    }

 
    getMenu()->getWindow().draw(getMenu()->getController().getPlayer().getState()->getCurrSkin());

    getMenu()->printScoreBoard();

    show();
}

void DieState::handleClick(const sf::Event::MouseButtonEvent& event)
{
    for (size_t i = 0; i < m_Buttons.size(); i++)
    {
        if (m_Buttons[i].second->getSprite().getGlobalBounds().contains(getMenu()->getWindow().mapPixelToCoords({ event.x, event.y })))
        {
            m_Buttons[i].second->execute();
            return;
        }
    }
}

void DieState::hoverButton(sf::Vector2i )
{
}

void DieState::updateOptions()
{
    m_Buttons.emplace_back(std::make_pair("Return2Menu", std::make_unique<Return2Menu>(getMenu())));
    m_Buttons.emplace_back(std::make_pair("StartGame", std::make_unique<StartGame>(getMenu())));

    // Update positions and textures for both buttons
    m_Buttons[0].second->updateSprite(sf::Vector2f(getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition().x + 400, 700), &Resources::instance().getOtherTexture(16));
    m_Buttons[0].second->adjustRec();

    m_Buttons[1].second->updateSprite(sf::Vector2f(getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition().x + 400, 580), &Resources::instance().getOtherTexture(13));
    m_Buttons[1].second->adjustRec();

    // Set desired size for both buttons
    sf::Vector2f desiredSize(300.0f, 100.0f);

    // Get current sizes of both buttons
    sf::Vector2u size0 = m_Buttons[0].second->getSprite().getTexture()->getSize();
    sf::Vector2u size1 = m_Buttons[1].second->getSprite().getTexture()->getSize();

    // Calculate scale factors for each dimension
    float scaleX0 = desiredSize.x / size0.x;
    float scaleY0 = desiredSize.y / size0.y;
    float scaleX1 = desiredSize.x / size1.x;
    float scaleY1 = desiredSize.y / size1.y;

    // Set the scale for both buttons
    m_Buttons[0].second->setscale(sf::Vector2f(scaleX0, scaleY0));
    m_Buttons[1].second->setscale(sf::Vector2f(scaleX1, scaleY1));
}


void DieState::show()
{
    for (int i = 0; i < m_Buttons.size(); i++)
    {
        getMenu()->getWindow().draw(m_Buttons[i].second->getSprite());
    }
}
