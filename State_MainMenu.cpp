#include "State_MainMenu.h"

State_MainMenu::State_MainMenu() {
	if (!m_font.loadFromFile("Assets/Fonts/KarmaFuture.ttf")) {
		std::cout << "Could not load font" << std::endl;
	}
	m_title.setFont(m_font);
	m_title.setString("Main menu");
	m_title.setCharacterSize(30);
//	m_title.setPosition()
}

