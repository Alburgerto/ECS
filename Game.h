#pragma once
#include "Shared.h"
#include "EntityManager.h"
#include "SystemManager.h"
#include "StateManager.h"

// Creates all managers and updates them. Also keeps track of time to keep a stable framerate
class Game {
public:
	Game();

	sf::RenderWindow& getWindow();
	void update();

private:
	void restartClock();

	sf::Time m_time;
	sf::Clock m_clock;
	sf::RenderWindow m_window;
	Shared m_shared;
	EntityManager m_entityManager;
	StateManager m_stateManager;
	SystemManager m_systemManager;
};

