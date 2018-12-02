#pragma once
#include <SFML\Graphics.hpp>	
#include "SystemManager.h"
#include "StateManager.h"

// Keeps pointer to resources used by different classes, to be passed as argument to constructor
// Might add pointer to map, etc., in the future. Not used as of now, might be helpful in the future when it would be necessary
// to pass 2+ arguments to some classes' constructors
class Shared {
public:
	Shared() : m_window(nullptr), m_systemManager(nullptr), m_stateManager(nullptr) {}
	sf::RenderWindow* m_window;
	SystemManager* m_systemManager;
	StateManager* m_stateManager;
};