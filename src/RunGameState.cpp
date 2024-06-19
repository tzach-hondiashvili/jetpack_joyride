#include "RunGameState.h"
#include "Menu.h"

RunGameState::RunGameState(Menu* menu)
{
    sf::View view(sf::FloatRect(0, 0, 1456, 960));
    m_view = view;

    m_scrollSpeed = 250.0f;

	updateMenu(menu);

    sf::Texture hallTexture = Resources::instance().getOtherTexture(22);
    sf::Texture backgroundTexture = Resources::instance().getOtherTexture(5);

    // Create sprites and scale them
    //sf::Sprite hallStartSprite(hallTexture);
    //sf::Sprite background1(backgroundTexture);
    //sf::Sprite background2(backgroundTexture);

    m_background1.setTexture(Resources::instance().getOtherTexture(5));
    m_background2.setTexture(Resources::instance().getOtherTexture(5));
    m_hall.setTexture(Resources::instance().getOtherTexture(22));

    m_background1.setScale(1456.f / 277, 960.f / 240);
    m_background2.setScale(1456.f / 277, 960.f / 240);
    m_hall.setScale(1456.f / 649, 960.f / 240);

    //hallStartSprite.setScale(1456.f / 649, 960.f / 240);
    //background1.setScale(1456.f / 277, 960.f / 240);
    //background2.setScale(1456.f / 277, 960.f / 240);

    // Initial positions for backgrounds
    float hallWidth = hallTexture.getSize().x * (1456.f / 649);  // Width of the hall sprite
    float backgroundWidth = 277.f * (1456.f / 277);  // Adjusted width of the background sprite

    m_hall.setPosition(0.f, 0.f);
    m_background1.setPosition(hallWidth, 0.f);
    m_background2.setPosition(hallWidth + backgroundWidth, 0.f);

}

void RunGameState::update(float deltaTime)
{
    m_view.move(m_scrollSpeed * deltaTime, 0.f);

    // Update background positions to create endless effect
    if ((m_background1.getPosition().x + 277.f * (1456.f / 277)) < (m_view.getCenter().x - m_view.getSize().x / 2))
    {
        m_background1.setPosition(m_background2.getPosition().x + 277.f * (1456.f / 277), 0.f);
    }
    if (m_background2.getPosition().x + 277.f * (1456.f / 277) < m_view.getCenter().x - m_view.getSize().x / 2)
    {
        m_background2.setPosition(m_background1.getPosition().x + 277.f * (1456.f / 277), 0.f);
    }

    getMenu()->updateController({m_view.getCenter().x - 600 , 760}, deltaTime);
    getMenu()->updateScoreBoard();

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

    getMenu()->printPlayer();

    getMenu()->printScoreBoard();
}

void RunGameState::handleClick(const sf::Event::MouseButtonEvent& event)
{

}

void RunGameState::hoverButton(sf::Vector2i position)
{

}

void RunGameState::moveHelpLeft()
{
}

void RunGameState::moveHelpRight()
{
}
