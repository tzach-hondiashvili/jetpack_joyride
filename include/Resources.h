#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Resources
{
public:
	static Resources& instance();
	void fillTextures();
	sf::Texture& getObjectTexture(int index);
	sf::Texture& getOtherTexture(int index);
	sf::Texture& getPlayerTexture(int index);
	sf::Texture& getHelpTexture(int index);
	void updateFont();
	const sf::Font& getFont();
	void fillTextureVectors(std::vector<std::string > names, std::vector<sf::Texture>& member);

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator = (const Resources&) = default;
	static Resources m_instance;
	std::vector<sf::Texture> m_objectsTextures;
	std::vector<sf::Texture> m_otherTextures;
	std::vector<sf::Texture> m_playerTextures;
	std::vector<sf::Texture> m_HelpTextures;
	sf::Font m_font;
};