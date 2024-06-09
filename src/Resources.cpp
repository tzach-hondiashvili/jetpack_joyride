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
														"k_PowerUpBox.png", //10
													  };

	std::vector<std::string> namesOfPlayerTextures = { "a_KingAvatar.png" //0
													   "b_KingDead.png"
													   "c_KingHit.png"
													   "d_KingWalking.png"
													   "e_BerryAvatar.png"
													   "f_BerryDead.png" //5
													   "g_BerryHit.png"
													   "h_BerryWalking.png"
													   "i_ScientistAvatar.png"
													   "j_ScientistDead.png"
													   "k_ScientistHit.png" //10
													   "l_ScientistWalking.png"
													   "m_SoldierAvatar.png"
													   "n_SoldierDead.png" 
													   "o_SoldierHit.png"
													   "p_SoldierWalking.png" //15
													   "q_GokuAvatar.png"
													   "r_SuperPowerFlyTank.png"
													   "s_SuperPowerRunner.png"
													   "t_SuperPowerTank.png"
																			//20
													  };

	std::vector<std::string> namesOfOtherTextures = {"a_arrow.png" //0
                                                     "b_Buy.png"
                                                     "c_Equip.png"
                                                     "d_GameMenu.png"
                                                     "e_GameSettingButton.png"
                                                     "f_Hall.png" //5
                                                     "g_HelpMenuOne.png"
                                                     "h_HelpMenuThree.png"
                                                     "i_HelpMenuTwo.png"
                                                     "j_helpOff.png"
                                                     "k_helpOn.png" //10
                                                     "l_PlaygameOff.png"
                                                     "m_PlayGameOn.png"
                                                     "q_Retry.png"
                                                     "p_Resume.png"
                                                     "r_Scientist.png" //15
                                                     "s_SettingQuit.png"
                                                     "t_SettingsMenu.png"
                                                     "u_SettingsOff.png"
                                                     "v_SettingsOn.png"
                                                     "w_ShopOff.png" //20
                                                     "x_ShopOn.png"
                                                     "y_StartOfHall.png"
                                                     "z_Title.png"
                                                     };
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