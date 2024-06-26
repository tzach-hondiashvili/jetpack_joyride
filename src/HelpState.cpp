#include "HelpState.h"
#include "Menu.h"

HelpState::HelpState(Menu* menu)
    :m_helpPage(0),m_backGround(sf::Sprite())
{
	updateMenu(menu);
    if (menu->finishedLoading())
    {
        m_helpButtons.emplace_back(std::make_pair("Return2Menu", std::make_unique<Return2Menu>(getMenu())));
        m_helpButtons.emplace_back(std::make_pair("HelpLeft", std::make_unique<HelpLeft>(getMenu())));
        m_helpButtons.emplace_back(std::make_pair("HelpRight", std::make_unique<HelpRight>(getMenu())));

        m_helpButtons[2].second->getSprite().setRotation(180);
    }

}
void HelpState::update(float )
{

}

void HelpState::print()
{
    m_backGround.setTexture(Resources::instance().getHelpTexture(m_helpPage));
    getMenu()->getWindow().draw(m_backGround);

    for (int i = 0; i < m_helpButtons.size(); i++)
    {
        if ((i == 1 && m_helpPage != 0) || (i == 0) || (i == 2 && m_helpPage != 5))
        {
            getMenu()->getWindow().draw(m_helpButtons[i].second->getSprite());
        }
    }
}
void HelpState::handleClick(const sf::Event::MouseButtonEvent& event)
{
    for (int i = 0; i < m_helpButtons.size(); i++)
    {
        if (m_helpButtons[i].second->getSprite().getGlobalBounds().contains(getMenu()->getWindow().mapPixelToCoords({event.x, event.y})))
        {
            if ((i == 1 && m_helpPage != 0) || (i == 0) || (i == 2 && m_helpPage != 5))
            {
                m_helpButtons[i].second->execute();
                return;
            }

        }
    }
}

void HelpState::hoverButton(sf::Vector2i )
{
}

void HelpState::moveHelpLeft()
{
    m_helpPage -= 1;
}

void HelpState::moveHelpRight()
{
    m_helpPage += 1;
}
