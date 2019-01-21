#pragma once
#include "Component.h"

// Component describing the position (x, y) of a set of nodes that form a path that an entity (with a CPhysics) will roam 
class CMovementAI : public Component {
public:
	CMovementAI();
	void readComponent(std::stringstream& l_data, std::shared_ptr<Entity> l_entity = nullptr);

	sf::Vector2f& getNextNode();
	void updateNode();

	sf::Vector2f& getDirection();
	void setDirection(const sf::Vector2f& l_direction);

private:
	std::vector<sf::Vector2f> m_path; // Each sf::Vector2f is a node
	sf::Vector2f m_direction; // (-1, 0) if to the left, (0, 1) if to the bottom, etc
	int m_nextNode; // Position of the last node traversed of m_path

};

