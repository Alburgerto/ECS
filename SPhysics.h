#pragma once
#include <unordered_map>
#include "System.h"

// Updates velocity in Physics component, updates sprites in Render component
class SPhysics : System {
public:
	SPhysics(Shared* l_shared);
	void update(float l_dT);
	void addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CPhysics>> l_entity);

private:
	std::unordered_map<std::shared_ptr<Entity>, std::shared_ptr<CPhysics>> m_entitiesPhysics;
};

