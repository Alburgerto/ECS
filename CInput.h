#pragma once
#include "Component.h"

// Defined in SInput.h, need to forward declare here, instead of including SInput's header to prevent circular includes
enum class Actions;

// Holds all actions doable by entity holding this system, as well as whether those actions are enabled at any given time
class CInput : public Component {
public:
	CInput();

	void addAction(Actions l_action); // Associates an actions (moving to the left, moving up, etc.) to an entity
	bool getAction(Actions l_action); // Returns whether action is currently active in an entity
	void setAction(Actions l_action, bool l_pressed = false); // Enables/disables actions
	void setAllActions(bool l_pressed = false); // Used for disabling all actions at the start of every loop
	
	void readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity = nullptr);
private:
	std::unordered_map<Actions, bool> m_actions; // <<MoveLeft, true>, <MoveUp, true>, <MoveRight, false>, <MoveDown, false>> => moving to the upper left

};

