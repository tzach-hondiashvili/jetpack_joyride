#include "DefaultMenu.h"
#include "Menu.h"

DefaultMenu::DefaultMenu(Menu* menu)
    :m_options()
{
	updateMenu(menu);
    if (menu->finishedLoading())
    {
        updateOptions();
    }

}

void DefaultMenu::update(float )
{

}

void DefaultMenu::print()
{
    static bool check = true;

    if (check)
    {
        getMenu()->getController().getPlayer().createPlayer();
        updateOptions();
        check = false;
    }
    // Textures are loaded, proceed to normal rendering
    sf::Sprite backgroundSprite(Resources::instance().getOtherTexture(3));
    getMenu()->getWindow().draw(backgroundSprite);
    show();
}

void DefaultMenu::handleClick(const sf::Event::MouseButtonEvent& event)
{
    for (size_t i = 0; i < m_options.size(); i++)
    {
        if (m_options[i].second->getSprite().getGlobalBounds().contains(getMenu()->getWindow().mapPixelToCoords({event.x, event.y})))
        {
            m_options[i].second->execute();
            return;
        }
    }
}

void DefaultMenu::hoverButton(sf::Vector2i position)
{
    for (int i = 0; i < m_options.size(); i++)
    {
        if (m_options[i].second->getSprite().getGlobalBounds().contains(
            getMenu()->getWindow().mapPixelToCoords({position.x, position.y})))
        {
            m_options[i].second->updateAnimation(true);
        }
        else
        {
            m_options[i].second->updateAnimation(false);
        }
    }
}

void DefaultMenu::moveHelpLeft()
{
}

void DefaultMenu::moveHelpRight()
{
}

void DefaultMenu::updateOptions()
{
    m_options.emplace_back(std::make_pair("Help", std::make_unique<Help>(getMenu())));
    m_options.emplace_back(std::make_pair("StartGame", std::make_unique<StartGame>(getMenu())));

}

void DefaultMenu::show()
{
    for (int i = 0; i < m_options.size(); i++)
    {
        getMenu()->getWindow().draw(m_options[i].second->getSprite());
    }
}
