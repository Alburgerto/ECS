#include "CMovementAI.h"
#include "Entity.h"

CMovementAI::CMovementAI() : m_nextNode(1), m_direction(0,0) {

}

void CMovementAI::readComponent(std::stringstream& l_data, std::shared_ptr<Entity> l_entity) {
	int x, y, nodeNumber;
	char delimiter;
	l_data >> nodeNumber;
	for (int i = 0; i < nodeNumber; ++i) {
		l_data >> delimiter >> x >> y;
		m_path.push_back(sf::Vector2f(x, y));
	}
	
}

sf::Vector2f& CMovementAI::getNextNode() {
	return m_path[m_nextNode];
}

// Advances node index. If it's out of bounds of the path size, it's reverted to 0.
void CMovementAI::updateNode() {
	if (++m_nextNode >= m_path.size()) {
		m_nextNode = 0;
	}
	std::cout << m_nextNode << std::endl;
}

sf::Vector2f& CMovementAI::getDirection() {
	return m_direction;
}

void CMovementAI::setDirection(const sf::Vector2f& l_direction) {
	m_direction = l_direction;
}

