#pragma once
#include <SFML/Graphics.hpp>
#include "Resources.h"

class LoadingScreen {
public:
    LoadingScreen();
    sf::Sprite &render();

private:
    sf::Sprite m_sprite;
};
