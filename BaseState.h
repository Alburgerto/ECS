#pragma once
#include "SFML/Graphics.hpp"


// Father to all states in the game (game, menu, etc), holding functionality shared among all states
class BaseState {
public:
	BaseState();
	virtual ~BaseState();

private:

};

