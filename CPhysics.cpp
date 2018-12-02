#include "CPhysics.h"
#include "Entity.h"

CPhysics::CPhysics() : m_velocity({0, 0}) {}

sf::Vector2i & CPhysics::getVelocity() {
	return m_velocity;
}

void CPhysics::setVelocity(const sf::Vector2i& l_velocity) {
	m_velocity = sf::Vector2i(m_speed * l_velocity.x, m_speed * l_velocity.y);
}

// Returns whether entity is static (rock, tree, etc., and therefore has no velocity)
bool CPhysics::isStatic() {
	return m_speed == 0;
}

void CPhysics::readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity) {
	int speed;
	l_line >> speed;
	m_speed = speed;
}

