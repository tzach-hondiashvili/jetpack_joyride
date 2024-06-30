#include "Menu.h"

Menu::Menu()
    :m_window(sf::VideoMode(1456, 960), "Jetpack Joyride"),m_finishedLoading(false)
{
    m_state = std::move(std::make_unique<DefaultMenu>(this));
}



void Menu::runMenu()
{
    std::future<void> loadingFuture = std::async(std::launch::async, [&]()
        {
            sf::Clock clock;
            Resources::instance().fillTextures();
            Resources::instance().updateFont();
            Resources::instance().updateGameMusic();
            Resources::instance().fillSoundFX();
            float deltaTime = clock.restart().asSeconds();

            m_state->update(deltaTime);
            Resources::instance().startMenuMusic();
        });

    m_window.setFramerateLimit(60);
    
    sf::Clock clock;

    while (m_window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
                m_state->handleClick(event.mouseButton);
                break;
            }
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
        m_state->update(deltaTime);

        m_window.clear();

        if (loadingFuture.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready)
        {
            m_finishedLoading = true;
            m_state->print();
        }
        else 
        {
            // Textures are still loading, display the loading screen
            m_window.draw(m_loadingScreen.render());
        }
        m_state->hoverButton(mousePosition);

        m_window.display();
    }

}

void Menu::quitGame()
{
	m_window.clear();
	m_window.close();
}

bool Menu::finishedLoading()
{
    return m_finishedLoading;
}

void Menu::updateController(sf::Vector2f pos, float time) 
{
    m_controller.getPlayer().handleInput();
    m_controller.updatePlayerPos(pos, time);

    m_controller.getMap().updatePickablesAnimation(time);
    m_controller.getMap().updateObstaclesAnimation(time);
    m_controller.getMap().updateEnemiesAnimation(pos,time);
}

void Menu::printScoreBoard()
{
    m_window.draw(m_scoreBoard.getDistance());
    m_window.draw(m_scoreBoard.getCoinsCounter());
}

void Menu::updateScoreBoard()
{
    m_scoreBoard.updateDistance(m_controller.getPlayer().getSprite().getPosition().x , m_controller.getPlayer().getSprite().getPosition());
    m_scoreBoard.updateCoins(m_controller.getPlayer().getCoinsCounter());
}

void Menu::printPlayer()
{
    if (m_controller.getPlayer().getSprite().getPosition().y != 750)
    {
        m_window.draw(m_controller.getPlayer().getFlame());
    }

    m_window.draw(m_controller.getPlayer().getSprite());
}

Controller& Menu::getController()
{
    return m_controller;
}

sf::RenderWindow& Menu::getWindow()
{
    return m_window;
}

std::unique_ptr<MenuState>& Menu::getState()
{
    return m_state;
}

Scoreboard& Menu::getSb()
{
    return m_scoreBoard;
}

void Menu::resetView()
{
    m_window.setView(m_window.getDefaultView());
}

void Menu::updateState(std::unique_ptr<MenuState> state)
{
    m_state = std::move(state);
}
