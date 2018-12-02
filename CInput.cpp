#include "CInput.h"
#include "SInput.h"

CInput::CInput() {}

// Add mechanics (moving left, jumping...) to entity
void CInput::addAction(Actions l_action) {
	m_actions.emplace(std::pair<Actions, bool>(l_action, false));
}

// Returns whether an action is currently active (button pressed)
bool CInput::getAction(Actions l_action) {
	auto action = m_actions.find(l_action);
	if (action == m_actions.end()) {
		std::cerr << "Action not found in entity" << std::endl;
		return false;
	}
	return action->second;
}

void CInput::setAction(Actions l_action, bool l_pressed) {
	auto action = m_actions.find(l_action);
	if (action == m_actions.end()) {
		std::cerr << "Action not found" << std::endl;
	}
	action->second = l_pressed;
}

void CInput::setAllActions(bool l_pressed) {
	for (auto& action : m_actions) {
		action.second = false;
	}
}

void CInput::readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity) {
	std::string action;

	while (l_line >> action) {
		if (action == "Left") {
			addAction(Actions::MoveLeft);
		}
		else if (action == "Right") {
			addAction(Actions::MoveRight);
		}
		else if (action == "Up") {
			addAction(Actions::MoveUp);
		}
		else if (action == "Down") {
			addAction(Actions::MoveDown);
		}
		// TODO more actions
	}
}
