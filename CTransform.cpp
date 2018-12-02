#include "CTransform.h"
#include "Entity.h"

CTransform::CTransform() {}

sf::Vector2f& CTransform::getPosition() {
	return m_position;
}

void CTransform::setPosition(const sf::Vector2f& l_position) {
	m_position = l_position;
}

void CTransform::movePosition(int l_offsetX, int l_offsetY) {
	m_position = sf::Vector2f(m_position.x + l_offsetX, m_position.y + l_offsetY);
}

void CTransform::readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity) {
	int x, y;
	l_line >> x >> y;
	m_position = sf::Vector2f(x, y);
}
