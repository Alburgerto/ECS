#include "Game.h"


// Window set to draw as many as 60 FPS (frames per second), but need to control the updating of the entities (their position, etc) 
// so that movement is the same regardless of computer specs (game running slower/faster in different PCs)
Game::Game() : m_window(sf::VideoMode(800, 600), "Game window"), m_systemManager(&m_shared), m_entityManager(&m_systemManager) {
	m_clock.restart();
	srand(time(nullptr));
	m_window.setFramerateLimit(60);
	m_shared.m_window = &m_window;		
	m_shared.m_stateManager = &m_stateManager;
	m_shared.m_systemManager = &m_systemManager;
	// m_stateManager.create(state_menu);
	// m_stateManager.create(state_game);
	// m_stateManager.activate(state_game);
	m_entityManager.createEntities("Assets/Entities"); // TODO: pass folder (containing 1+ LUA files describing entities) as argument
}

sf::RenderWindow& Game::getWindow() {
	return m_window;
}

void Game::update() {
	m_systemManager.update(m_time.asSeconds());
	restartClock();
}

void Game::restartClock() {
	m_time = m_clock.restart();
}
