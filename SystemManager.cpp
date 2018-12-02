#include "SystemManager.h"
#include "Shared.h"

SystemManager::SystemManager(Shared* l_shared) : m_shared(l_shared), m_inputSystem(l_shared), m_physicsSystem(l_shared), m_colliderSystem(l_shared), m_renderSystem(l_shared) {}

// First need to check user input, then update positions with delta time, lastly entities are rendered after their positions are updated
void SystemManager::update(float l_dT) {
	m_inputSystem.update(m_shared->m_window);
	m_physicsSystem.update(l_dT);
	m_renderSystem.update(m_shared->m_window);
}

SInput* SystemManager::getInputSystem() {
	return &m_inputSystem;
}

SPhysics* SystemManager::getPhysicsSystem() {
	return &m_physicsSystem;
}

SCollider* SystemManager::getColliderSystem() {
	return &m_colliderSystem;
}

SRender* SystemManager::getRenderSystem() {
	return &m_renderSystem;
}