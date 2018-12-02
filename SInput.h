#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "System.h"

// To add other actions: dash, etc
enum class Actions { MoveLeft, MoveRight, MoveUp, MoveDown };

// Handles window events, updates input component (enables actions if their corresponding key is pressed)
class SInput : System {
public:
	SInput(Shared* l_shared);
	void update(sf::RenderWindow* l_window);
	void addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CInput>> l_entity);

private:
	std::unordered_map<std::shared_ptr<Entity>, std::shared_ptr<CInput>> m_entitiesInput;

};

