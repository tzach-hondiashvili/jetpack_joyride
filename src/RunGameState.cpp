#include "RunGameState.h"
#include "Menu.h"
#include "DieState.h"

RunGameState::RunGameState(Menu* menu)
{

    updateMenu(menu);
    updateOptions();
    Resources::instance().endMenuMusic();
    Resources::instance().startGameMusic();


    sf::View view(sf::FloatRect(0, 0, 1456, 960));
    m_view = view;

    m_scrollSpeed = 250.0f;


    sf::Texture hallTexture = Resources::instance().getOtherTexture(22);
    sf::Texture backgroundTexture = Resources::instance().getOtherTexture(5);

    m_background1.setTexture(Resources::instance().getOtherTexture(5));
    m_background2.setTexture(Resources::instance().getOtherTexture(5));
    m_hall.setTexture(Resources::instance().getOtherTexture(22));

    m_background1.setScale(1456.f / 277, 960.f / 240);
    m_background2.setScale(1456.f / 277, 960.f / 240);
    m_hall.setScale(1456.f / 649, 960.f / 240);

    // Initial positions for backgrounds
    float hallWidth = hallTexture.getSize().x * (1456.f / 649);  // Width of the hall sprite
    float backgroundWidth = 277.f * (1456.f / 277);  // Adjusted width of the background sprite

    m_hall.setPosition(0.f, 0.f);
    m_background1.setPosition(hallWidth, 0.f);
    m_background2.setPosition(hallWidth + backgroundWidth, 0.f);

}

RunGameState::~RunGameState()
{

}

void RunGameState::update(float deltaTime)
{
    if (getMenu()->getController().getPlayer().getLives() == 0)
    {
        std::unique_ptr temp = std::make_unique<DieState>(getMenu(),m_background1,m_background2);
        getMenu()->updateState(std::move(temp));
        return;
    }

    m_view.move(m_scrollSpeed * deltaTime, 0.f);

    getMenu()->getController().checkCollision();

    // Update background positions to create endless effect
    if ((m_background1.getPosition().x + 277.f * (1456.f / 277)) < (m_view.getCenter().x - m_view.getSize().x / 2))
    {
        m_background1.setPosition(m_background2.getPosition().x + 277.f * (1456.f / 277), 0.f);
        getMenu()->getController().getMap().updatePickables(m_background1.getPosition());
        getMenu()->getController().getMap().updateObstacles(m_background1.getPosition());
        getMenu()->getController().getMap().updateEnemies(m_background1.getPosition(), getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition());
        getMenu()->getController().getMap().updateScientists(m_background1.getPosition(), getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition());
    }
    if (m_background2.getPosition().x + 277.f * (1456.f / 277) < m_view.getCenter().x - m_view.getSize().x / 2)
    {
        m_background2.setPosition(m_background1.getPosition().x + 277.f * (1456.f / 277), 0.f);
        getMenu()->getController().getMap().updatePickables(m_background2.getPosition());
        getMenu()->getController().getMap().updateObstacles(m_background2.getPosition());
        getMenu()->getController().getMap().updateEnemies(m_background2.getPosition(), getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition());
        getMenu()->getController().getMap().updateScientists(m_background2.getPosition(), getMenu()->getController().getPlayer().getState()->getCurrSkin().getPosition());
    }

    getMenu()->updateController({m_view.getCenter().x - 600 , 760}, deltaTime);
    getMenu()->updateScoreBoard();
    m_options[0].second->updateSprite(getMenu()->getSb().getDistance().getPosition() + sf::Vector2f{1300,0}, &Resources::instance().getOtherTexture(4));

    m_scrollSpeed += 5.0f * deltaTime;

    getMenu()->getWindow().setView(m_view);
}

void RunGameState::print()
{
    if (m_view.getCenter().x - 770 * 2 < m_hall.getTexture()->getSize().x)
    {
        getMenu()->getWindow().draw(m_hall); // Draw hall if it's still visible
    }
    getMenu()->getWindow().draw(m_background1);
    getMenu()->getWindow().draw(m_background2);
    
    //print pickable object list
    for (auto it = getMenu()->getController().getMap().getPickables().begin();it!= getMenu()->getController().getMap().getPickables().end();it++)
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
        if (!(*it)->getIsLaunchPlayed())
        {
            getMenu()->getWindow().draw((*it)->getWarning());
        }
    }
    for (auto it = getMenu()->getController().getMap().getScientists().begin(); it != getMenu()->getController().getMap().getScientists().end(); it++)
    {
        getMenu()->getWindow().draw((*it)->getSprite());
    }

    getMenu()->printPlayer();

    getMenu()->printScoreBoard();

    show();
}

void RunGameState::handleClick(const sf::Event::MouseButtonEvent& event)
{
    for (size_t i = 0; i < m_options.size(); i++)
    {
        if (m_options[i].second->getSprite().getGlobalBounds().contains(getMenu()->getWindow().mapPixelToCoords({ event.x, event.y })))
        {
            m_options[i].second->execute();
            return;
        }
    }

}

void RunGameState::hoverButton(sf::Vector2i )
{

}

void RunGameState::moveHelpLeft()
{
}

void RunGameState::moveHelpRight()
{
}

void RunGameState::updateOptions()
{

    m_options.emplace_back(std::make_pair("Return2Menu", std::make_unique<Return2Menu>(getMenu())));

    m_options[0].second->updateSprite({1400,900}, &Resources::instance().getOtherTexture(4));
}

void RunGameState::show()
{
    for (int i = 0; i < m_options.size(); i++)
    {
        getMenu()->getWindow().draw(m_options[i].second->getSprite());
    }
}

