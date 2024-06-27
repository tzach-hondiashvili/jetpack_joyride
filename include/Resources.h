#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Audio.hpp>

class Resources
{
public:
	static Resources& instance();
	void fillTextures();

	sf::Texture& getObjectTexture(int index);
	sf::Texture& getOtherTexture(int index);
	sf::Texture& getPlayerTexture(int index);
	sf::Texture& getHelpTexture(int index);
	sf::SoundBuffer& getSoundEffect(int index);

	void startGameMusic();
	void endGameMusic();

	void startMenuMusic();
	void endMenuMusic();
	

	void updateFont();
	const sf::Font& getFont();
	void fillTextureVectors(std::vector<std::string > names, std::vector<sf::Texture>& member);
	void updateGameMusic();
	void fillSoundFX();

private:
	Resources();
	Resources(const Resources&) = default;
	Resources& operator = (const Resources&) = default;
	static Resources m_instance;

	std::vector<sf::Texture> m_objectsTextures;
	std::vector<sf::Texture> m_otherTextures;
	std::vector<sf::Texture> m_playerTextures;
	std::vector<sf::Texture> m_HelpTextures;


	std::vector <sf::SoundBuffer> m_soundFX;

	sf::Music m_gameMusic;
	sf::Music m_MenuMusic;


	sf::Font m_font;
};