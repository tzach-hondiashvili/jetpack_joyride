#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Resources
{
public:
	static Resources& instance();
	void fillTextures();
	sf::Texture& getTexture(int index);
	void updateFont();
	const sf::Font& getFont();
private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator = (const Resources&) = default;
	static Resources m_instance;
	std::vector<sf::Texture> m_textures;
	sf::Font m_font;
};