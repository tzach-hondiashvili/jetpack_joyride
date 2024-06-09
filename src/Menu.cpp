#include "Menu.h"

Menu::Menu()
	:m_window()
{
}

void Menu::runGame()
{
    std::cout << "hi bodeki" << std::endl;
}

void Menu::runMenu()
{
    Resources::instance().fillTextures();
    Resources::instance().updateFont();
    m_window.setFramerateLimit(60);

    updateOptions();

    sf::Sprite backgroundSprite(Resources::instance().getOtherTexture(3));


    while (m_window.isOpen())
    {
        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
                handleButtonClick(event.mouseButton);
                break;
            }
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

        m_window.clear();
        m_window.draw(backgroundSprite);
        show();
        //hoverButton(mousePosition);
        m_window.display();
    }

}

void Menu::runHelp()
{
    std::cout << "Help me" << std::endl;
}

void Menu::quitGame()
{
	m_window.clear();
	m_window.close();
}

void Menu::show()
{
	for (int i = 0; i < m_options.size(); i++)
	{
		m_window.draw(m_options[i].second->getSprite());
	}
}

void Menu::updateOptions()
{
	m_options.push_back(std::make_pair("Help", std::unique_ptr<Help>()));
	m_options.push_back(std::make_pair("StartGame", std::unique_ptr<StartGame>()));
}

void Menu::handleButtonClick(const sf::Event::MouseButtonEvent& event)
{
    for (size_t i = 0; i < m_options.size(); i++)
    {
        if (m_options[i].second->getSprite().getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y })))
        {
            m_options[i].second->execute();
        }
    }
}
