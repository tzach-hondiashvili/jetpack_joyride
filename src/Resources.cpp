#include "Resources.h"
#include <iostream>
#include <string>

Resources Resources::m_instance = Resources();

Resources& Resources::instance()
{
	return m_instance;
}


void Resources::fillTextures()
{
	std::vector<std::string> namesOfTextures = { };
	sf::Texture temp;
	for (int i = 0; i < namesOfTextures.size(); i++)
	{
		if (temp.loadFromFile(namesOfTextures[i]))
		{
			m_textures.push_back(temp);
		}
		else
		{
			std::cerr << "Failed to load texture: " << namesOfTextures[i] << std::endl;
		}
	}
}

sf::Texture& Resources::getTexture(int index)
{
	return m_textures[index];
}

void Resources::updateFont()
{
	m_font.loadFromFile("Jetpackia.ttf");
}

const sf::Font& Resources::getFont()
{
	return m_font;
}

Resources::Resources()
	:m_textures({}), m_font(sf::Font())
{
}