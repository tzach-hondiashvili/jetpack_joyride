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
	std::vector<std::string > namesOfObjectTextures = { "" };
	std::vector<std::string> namesOfPlayerTextures = { "" };
	std::vector<std::string> namesOfOtherTextures = {""};

	sf::Texture temp;

	//objects
	for (int i = 0; i < namesOfObjectTextures.size(); i++)
	{
		if (temp.loadFromFile(namesOfObjectTextures[i]))
		{
			m_objectsTextures.push_back(temp);
		}
		else
		{
			std::cerr << "Failed to load texture: " << namesOfObjectTextures[i] << std::endl;
		}
	}
	//player
	for (int i = 0; i < namesOfPlayerTextures.size(); i++)
	{
		if (temp.loadFromFile(namesOfPlayerTextures[i]))
		{
			m_playerTextures.push_back(temp);
		}
		else
		{
			std::cerr << "Failed to load texture: " << namesOfPlayerTextures[i] << std::endl;
		}
	}
	//other
	for (int i = 0; i < namesOfOtherTextures.size(); i++)
	{
		if (temp.loadFromFile(namesOfOtherTextures[i]))
		{
			m_otherTextures.push_back(temp);
		}
		else
		{
			std::cerr << "Failed to load texture: " << namesOfOtherTextures[i] << std::endl;
		}
	}
}

sf::Texture& Resources::getObjectTexture(int index)
{
	return m_objectsTextures[index];
}

sf::Texture& Resources::getOtherTexture(int index)
{
	return m_otherTextures[index];
}

sf::Texture& Resources::getPlayerTexture(int index)
{
	return m_playerTextures[index];
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
	:m_objectsTextures({}), m_font(sf::Font()),m_otherTextures({}),m_playerTextures({})
{
}