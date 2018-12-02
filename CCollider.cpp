#include "CCollider.h"
#include "Entity.h"
#include "SystemManager.h"

CCollider::CCollider() : m_debug(false), m_systemManager(nullptr) {
	initialize();
}

CCollider::CCollider(SystemManager* l_systemManager) : m_debug(true), m_systemManager(l_systemManager) {
	initialize();
}

void CCollider::initialize() {
	m_collisions.emplace(Direction::Left, false);
	m_collisions.emplace(Direction::Right, false);
	m_collisions.emplace(Direction::Up, false);
	m_collisions.emplace(Direction::Down, false);
}

sf::IntRect& CCollider::getAABB() {
	return m_AABB;
}

void CCollider::setPosition(const sf::Vector2f& l_position) {
	m_AABB = sf::IntRect(l_position.x, l_position.y + m_yOffset, m_size.x, m_size.y);
	if (m_debug) {
		m_debugRect.setPosition(l_position.x, l_position.y + m_yOffset);
	}
}

void CCollider::setCollision(Direction l_direction, bool l_collision) {
	m_collisions.find(l_direction)->second = l_collision;
}

void CCollider::resetCollisions() {
	for (auto& pair : m_collisions) {
		pair.second = 0;
	}
}

bool CCollider::getCollision(Direction l_direction) {
	return m_collisions.find(l_direction)->second;
}

bool CCollider::isDebug() {
	return m_debug;
}

sf::RectangleShape& CCollider::getDebugRect() {
	return m_debugRect;
}

void CCollider::readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity) {
	int width, height, yOffset, debug;
	l_line >> width >> height >> yOffset >> debug;
	m_size = sf::Vector2i(width, height - yOffset);
	m_yOffset = yOffset;
	sf::Vector2f transformPosition = l_entity->getComponent<CTransform>()->getPosition();
	sf::Vector2i colliderPosition = sf::Vector2i(transformPosition.x, transformPosition.y + yOffset);
	m_AABB = sf::IntRect(colliderPosition, m_size);
//	std::cout << l_entity->getName() << ": " << m_AABB.left << " " << m_AABB.top << " " << m_AABB.width << " " << m_AABB.height << std::endl;

	// Debug render
	if (debug && m_systemManager) {
		m_debugRect.setPosition(colliderPosition.x, colliderPosition.y + yOffset);
		m_debugRect.setSize(sf::Vector2f(width, height - yOffset));
		m_debugRect.setFillColor(sf::Color(0, 0, 0, 0)); // 0 alpha, so it's transparent inside
		m_debugRect.setOutlineThickness(-5);
		m_debugRect.setOutlineColor(sf::Color::Green);
//		std::cout << l_entity->getName() << ": " << m_debugRect.getPosition().x << " " << m_debugRect.getPosition().y << " " << m_debugRect.getSize().x << " " << m_debugRect.getSize().y << std::endl;

		m_systemManager->getRenderSystem()->addDebugAABB(&m_debugRect);
	}
}
