#pragma once
#include "BaseState.h"
#include <array>

// Gives option to resume game, as well as to go back to the menu
class State_Pause : public BaseState {
public:
	State_Pause(Shared* l_shared);

	void input();
	void draw(float l_dT);
	void update(float l_dT);
	void changeState();

	void enable();

private:
	sf::Font m_font;
	std::array<sf::Text, 2> m_options; // Resume, Menu. TODO: save option
	int m_chosenOption;

};

