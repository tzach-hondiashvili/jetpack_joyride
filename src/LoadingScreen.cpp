#include "LoadingScreen.h"

LoadingScreen::LoadingScreen() 
{
    static sf::Texture temp;
    temp.loadFromFile("loading.png");
    m_sprite.setTexture(temp);
}

sf::Sprite &LoadingScreen::render() 
{
    return m_sprite;
}
