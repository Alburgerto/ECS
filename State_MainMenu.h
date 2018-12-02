#pragma once
#include "BaseState.h"
#include <iostream>

// Will hold data (game's title, buttons to press (text + collision boxes) to go to Game/Credits/Options state) as well as functionality to go to those states when clicking buttons
class State_MainMenu : public BaseState {
public:
	State_MainMenu();

private:
	sf::Text m_title;
	sf::Font m_font;
};

