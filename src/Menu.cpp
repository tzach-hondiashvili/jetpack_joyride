#include "Menu.h"

Menu::Menu()
    :m_window(sf::VideoMode(1456, 960), "Jetpack Joyride"),m_runHelp(true),m_helpPage(0)
{
}



void Menu::runMenu()
{
    // Load textures in a separate thread
    std::future<void> loadingFuture = std::async(std::launch::async, [&]()
    {
        Resources::instance().fillTextures();
        Resources::instance().updateFont();
        updateOptions();
    });

    m_window.setFramerateLimit(60);

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

        // Check if textures are still loading
        if (loadingFuture.wait_for(std::chrono::milliseconds(0)) == std::future_status::ready) 
        {
            // Textures are loaded, proceed to normal rendering
            sf::Sprite backgroundSprite(Resources::instance().getOtherTexture(3));
            m_window.draw(backgroundSprite);
            show();
        }
        else {
            // Textures are still loading, display the loading screen
            m_window.draw(m_loadingScreen.render());
        }
        hoverButton(mousePosition);
        m_window.display();
    }

}

void Menu::runGame()
{
    m_controller.getPlayer().createPlayer();

    // Load player sprite
    sf::Sprite playerSprite = m_controller.getPlayer().getSprite();

    // Load hall and background textures
    sf::Texture hallTexture = Resources::instance().getOtherTexture(22);
    sf::Texture backgroundTexture = Resources::instance().getOtherTexture(5);

    // Create sprites and scale them
    sf::Sprite hallStartSprite(hallTexture);
    sf::Sprite background1(backgroundTexture);
    sf::Sprite background2(backgroundTexture);

    hallStartSprite.setScale(1456.f / 649, 960.f / 240);
    background1.setScale(1456.f / 277, 960.f / 240);
    background2.setScale(1456.f / 277, 960.f / 240);

    // Initial positions for backgrounds
    float hallWidth = hallTexture.getSize().x * (1456.f / 649);  // Width of the hall sprite
    float backgroundWidth = 277.f * (1456.f / 277);  // Adjusted width of the background sprite

    hallStartSprite.setPosition(0.f, 0.f);
    background1.setPosition(hallWidth, 0.f);
    background2.setPosition(hallWidth + backgroundWidth, 0.f);

    sf::Clock clock;
    float scrollSpeed = 150.0f; // Initial scroll speed

    sf::View view(sf::FloatRect(0, 0, 1456, 960));

    while (m_window.isOpen()) 
    {
        float deltaTime = clock.restart().asSeconds();
        for (auto event = sf::Event{}; m_window.pollEvent(event);) {

            switch (event.type) 
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
                break;
            }
        }

        //updateblock
        // 
        // Move the view to the right
        view.move(scrollSpeed * deltaTime, 0.f);

        // Update background positions to create endless effect
        if (background1.getPosition().x + backgroundWidth < view.getCenter().x - view.getSize().x / 2)
        {
            background1.setPosition(background2.getPosition().x + backgroundWidth, 0.f);
        }
        if (background2.getPosition().x + backgroundWidth < view.getCenter().x - view.getSize().x / 2)
        {
            background2.setPosition(background1.getPosition().x + backgroundWidth, 0.f);
        }

        updateController({view.getCenter().x - 600 , 760 },deltaTime);
        updateScoreBoard();

        // Increase scroll speed over time
        scrollSpeed += 5.0f * deltaTime;

        //print block
        m_window.setView(view);
        m_window.clear();
        // Draw sprites
        if (view.getCenter().x - 760*2 < hallTexture.getSize().x) 
        {
            m_window.draw(hallStartSprite); // Draw hall if it's still visible
        }
        m_window.draw(background1);
        m_window.draw(background2);
        printScoreBoard();

        m_window.draw(m_controller.getPlayer().getSprite());
        //hoverButton(mousePosition);
        m_window.display();
    }
}

void Menu::runHelp()
{
    m_helpPage = 0;
    m_runHelp = false;

    while (m_window.isOpen() && !m_runHelp)
    {
        sf::Sprite backgroundSprite(Resources::instance().getHelpTexture(m_helpPage));

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
                handleHelpButtonClick(event.mouseButton);
                break;
            }
        }
        sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);

        m_window.clear();
        m_window.draw(backgroundSprite);
        showHelpButtons();
        //hoverButton(mousePosition);
        m_window.display();
    }
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
	m_options.emplace_back(option("Help", std::move(std::make_unique<Help>(this))));
	m_options.emplace_back(option("StartGame", std::move(std::make_unique<StartGame>(this))));

    m_helpButtons.emplace_back(option("Return2Menu", std::move(std::make_unique<Return2Menu>(this))));
    m_helpButtons.emplace_back(option("HelpLeft", std::move(std::make_unique<HelpLeft>(this))));
    m_helpButtons.emplace_back(option("HelpRight", std::move(std::make_unique<HelpRight>(this))));

    m_helpButtons[2].second->getSprite().setRotation(180);

}

void Menu::handleButtonClick(const sf::Event::MouseButtonEvent& event)
{
    for (size_t i = 0; i < m_options.size(); i++)
    {
        if (m_options[i].second->getSprite().getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y })))
        {
            m_options[i].second->execute();
            return;
        }
    }
}

void Menu::handleHelpButtonClick(const sf::Event::MouseButtonEvent& event)
{
    for (int i = 0; i < m_helpButtons.size(); i++)
    {
        if (m_helpButtons[i].second->getSprite().getGlobalBounds().contains(m_window.mapPixelToCoords({event.x, event.y})))
        {
            if ((i == 1 && m_helpPage != 0) || (i ==0) || (i == 2 && m_helpPage != 5))
            {
                m_helpButtons[i].second->execute();
            }
            
        }
    }
}

void Menu::showHelpButtons()
{
    for (int i = 0; i < m_helpButtons.size(); i++)
    {
        if ((i == 1 && m_helpPage != 0) || (i == 0) || (i == 2 && m_helpPage != 5))
        {
            m_window.draw(m_helpButtons[i].second->getSprite());
        }
    }
    
}

void Menu::return2Menu()
{
    m_runHelp = true;
}

void Menu::moveHelpLeft()
{
    m_helpPage -= 1;
}

void Menu::moveHelpRight()
{
    m_helpPage += 1;
}

void Menu::updateController(sf::Vector2f pos, float time) 
{
    m_controller.getPlayer().handleInput();
    m_controller.updatePlayerPos(pos, time);
}

void Menu::printScoreBoard()
{
    m_window.draw(m_scoreBoard.getDistance());
}

void Menu::updateScoreBoard()
{
    m_scoreBoard.updateDistance(m_controller.getPlayer().getSprite().getPosition().x , m_controller.getPlayer().getSprite().getPosition());
}

void Menu::hoverButton(sf::Vector2i position)
{
    for (int i = 0; i < m_options.size(); i++)
    {
        if (m_options[i].second->getSprite().getGlobalBounds().contains(
            m_window.mapPixelToCoords({ position.x, position.y })))
        {
            m_options[i].second->updateAnimation(true);
        }
        else
        {
            m_options[i].second->updateAnimation(false);
        }
    }
}
