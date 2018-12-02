#pragma once
#include "SInput.h"
#include "SPhysics.h"
#include "SCollider.h"
#include "SRender.h"

class Shared;

// Creates and calls all systems update methods
// Every system will keep a map of entities and their respective render/input/etc component
class SystemManager {
public:
	SystemManager(Shared* l_shared);

	void update(float l_dT);
	SInput* getInputSystem();
	SPhysics* getPhysicsSystem();
	SCollider* getColliderSystem();
	SRender* getRenderSystem();

private:
	Shared* m_shared;
	SInput m_inputSystem;
	SPhysics m_physicsSystem;
	SCollider m_colliderSystem;
	SRender m_renderSystem;
};

