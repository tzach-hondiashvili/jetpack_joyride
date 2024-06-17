#include "MenuState.h"
#include "Menu.h"

MenuState::MenuState()
	:m_Menu(nullptr)
{
}

void MenuState::updateMenu(Menu* menu)
{
	m_Menu = menu;
}

Menu* MenuState::getMenu()
{
	return m_Menu;
}
