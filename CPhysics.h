#pragma once
#include "Component.h"

// Holds velocity + direction entity is moving towards. Hollision needs to be its own separate component, as there might be entities with movable sprites with no collision
class CPhysics : public Component {
public:
	CPhysics();

	sf::Vector2i& getVelocity();
	void setVelocity(const sf::Vector2i& l_velocity); 
	bool isStatic();

	void readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity = nullptr);
private:
	int m_speed; // To be multiplied by m_direction to move m_velocity pixels in each axis. Int, not float, as it's the amount of pixels to move in any given frame
	sf::Vector2i m_velocity; // (-1 * m_velocity, -1 * m_velocity) -> left, up. (-1, 1) -> left, down. (1, -1) -> right, up. (1, 1) -> right, down.
};

