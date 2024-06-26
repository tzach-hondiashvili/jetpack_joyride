#include "DieState.h"
#include "Menu.h"
#include "Return2Menu.h"

DieState::DieState(Menu* menu,sf::Sprite& bg1, sf::Sprite& bg2)
    :
    m_backGround1(std::move(bg1)),
    m_backGround2(std::move(bg2))
{
    updateMenu(menu);
}

void DieState::update(float deltaTime)
{
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

 
    getMenu()->getWindow().draw(getMenu()->getController().getPlayer().getSprite());

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

    m_Buttons[0].second->updateSprite(sf::Vector2f(getMenu()->getController().getPlayer().getSprite().getPosition().x + 200,300),&Resources::instance().getOtherTexture(13));
}

void DieState::show()
{
    for (int i = 0; i < m_Buttons.size(); i++)
    {
        getMenu()->getWindow().draw(m_Buttons[i].second->getSprite());
    }
}
