#pragma once
#include <unordered_map>
#include <typeindex>
#include "BaseState.h"

class Shared;

class StateManager {
public:
	StateManager();



private:
	std::unordered_map<std::type_index, std::shared_ptr<BaseState>> m_states;

};

