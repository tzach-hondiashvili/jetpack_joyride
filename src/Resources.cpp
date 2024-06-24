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
	std::vector<std::string > namesOfObjectTextures = { "a_Coin.png", //0
														"b_Exhaust.png",
														"c_Glitter.png",
														"d_Laser.png",
														"e_LasersBeam.png",
														"f_Lights.png", //5
														"g_Missile.png",
														"h_MissileIncoming.png",
														"i_MissileWarning.png",
														"j_Piggy.png",
														"k_PowerUpBox.png" //10
													  };

	std::vector<std::string> namesOfPlayerTextures = { "a_KingAvatar.png", //0
													   "b_KingDead.png",
													   "c_KingHit.png",
													   "d_KingWalking.png",
													   "e_BerryAvatar.png",
													   "f_BerryDead.png", //5
													   "g_BerryHit.png",
													   "h_BerryWalking.png",
													   "i_ScientistAvatar.png",
													   "j_ScientistDead.png",
													   "k_ScientistHit.png", //10
													   "l_ScientistWalking.png",
													   "m_SoldierAvatar.png",
													   "n_SoldierDead.png" ,
													   "o_SoldierHit.png",
													   "p_SoldierWalking.png", //15
													   "q_GokuAvatar.png",
													   "r_SuperPowerFlyTank.png",
													   "s_SuperPowerRunner.png",
													   "t_SuperPowerTank.png"
																			//20
													  };

	std::vector<std::string> namesOfOtherTextures = {"a_arrow.png", //0
                                                     "b_Buy.png",
                                                     "c_Equip.png",
                                                     "d_GameMenu.png",
                                                     "e_GameSettingButton.png",
                                                     "f_Hall.png", //5
                                                     "g_HelpMenuOne.png",
                                                     "h_HelpMenuThree.png",
                                                     "i_HelpMenuTwo.png",
                                                     "j_helpOff.png",
                                                     "k_helpOn.png", //10
                                                     "l_PlaygameOff.png",
                                                     "m_PlayGameOn.png",
                                                     "q_Retry.png",
                                                     "p_Resume.png",
                                                     "r_Scientist.png" ,//15
                                                     "s_SettingQuit.png",
                                                     "t_SettingsMenu.png",
                                                     "u_SettingsOff.png",
                                                     "v_SettingsOn.png",
                                                     "w_ShopOff.png", //20
                                                     "x_ShopOn.png",
                                                     "y_StartOfHall.png",
                                                     "z_Title.png"
                                                     };

	std::vector<std::string > namesOfHelpTextures = { "1.png", //0
														"2.png",
														"3.png",
														"4.png",
														"5.png",
														"6.png", //5												
	                                                };
	

	fillTextureVectors(namesOfHelpTextures,m_HelpTextures);
	fillTextureVectors(namesOfObjectTextures,m_objectsTextures);
	fillTextureVectors(namesOfOtherTextures,m_otherTextures);
	fillTextureVectors(namesOfPlayerTextures,m_playerTextures);
}

void Resources::fillTextureVectors(std::vector<std::string > names, std::vector<sf::Texture> &member)
{
	sf::Texture temp;

	for (int i = 0; i < names.size(); i++)
	{
		if (temp.loadFromFile(names[i]))
		{
			member.emplace_back(temp);
		}
		else
		{
			std::cerr << "Failed to load texture: " << names[i] << std::endl;
		}
	}
}

void Resources::updateGameMusic()
{
	m_gameMusic.openFromFile("JetpackJoyrideMusic.ogg");
	m_gameMusic.setVolume(50);
}

void Resources::fillSoundFX()
{
	std::vector<std::string> namesOfSounds =
	{
		"a_coin.ogg",		   //0
		"b_getPowerSound.ogg", //1
		"c_hitSound.ogg",      //2  
		"d_MissileAlarm.ogg",  //3
		"e_missileLaunch.ogg", //4
		"f_ZapperSound.ogg",   //5
	};

	for (int i = 0; i < namesOfSounds.size(); i++)
	{
		sf::SoundBuffer temp;
		temp.loadFromFile(namesOfSounds[i]);
		m_soundFX.push_back(temp);
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

sf::Texture& Resources::getHelpTexture(int index)
{
	return m_HelpTextures[index];
}

sf::SoundBuffer& Resources::getSoundEffect(int index)
{
	return m_soundFX[index];
}

void Resources::startGameMusic()
{
	m_gameMusic.play();
	m_gameMusic.setLoop(true);
}

void Resources::endGameMusic()
{
	m_gameMusic.stop();
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