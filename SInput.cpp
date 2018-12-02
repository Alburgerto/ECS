#include "SInput.h"


SInput::SInput(Shared* l_shared) : System(l_shared) {}

// Checks for events (sf::Event::LostFocus, GainedFocus, Closed...) every frame related to the window, as well as user input.
// Events related to window are hardcoded, as well as the actions available for any given entity (move up, down, dash, attack...?)
void SInput::update(sf::RenderWindow* l_window) {
	sf::Event event;
	while (l_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape) {
			l_window->close();
		}

		for (auto& entity : m_entitiesInput) {
			entity.second->setAllActions(false); // No actions happening at the start of each frame
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				entity.second->setAction(Actions::MoveLeft, true);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				entity.second->setAction(Actions::MoveRight, true);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				entity.second->setAction(Actions::MoveUp, true);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				entity.second->setAction(Actions::MoveDown, true);
			}
		}
	}
}

void SInput::addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CInput>> l_entity) {
	m_entitiesInput.emplace(l_entity);
}
