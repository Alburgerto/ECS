#pragma once
#include "BaseState.h"
#include <array>

// Goes back to menu
class State_Victory : public BaseState {
public:
	State_Victory(Shared* l_shared);

	void input();
	void draw(float l_dT);
	void update(float l_dT);
	void changeState();

	void enable();

private:
	sf::Font m_font;
	std::array<sf::Text, 2> m_options; // Resume, Menu. TODO: save option
};

