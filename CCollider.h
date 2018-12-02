#pragma once
#include "Component.h"

class SystemManager;
enum class Direction { Left, Right, Up, Down };

// Holds information about AABB (collision box) of entity to have collision with other entities with collider components.
// Intersection checking happens @ SCollider
class CCollider : public Component {
public:
	CCollider();
	CCollider(SystemManager* l_systemManager);

	sf::IntRect& getAABB();

	void setPosition(const sf::Vector2f& l_position);
	void setCollision(Direction l_direction, bool l_collision);
	void resetCollisions(); // Disables all collisions
	bool getCollision(Direction l_direction);
	bool isDebug();
	sf::RectangleShape& getDebugRect();

	void readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity = nullptr);

private:
	void initialize();

	bool m_debug;
	int m_yOffset;
	sf::RectangleShape m_debugRect;
	sf::IntRect m_AABB; // will hold (x, y) + (width, length) of collision box.
	sf::Vector2i m_size; // Size of AABB box, kept as member of the class as it won't change (position will)
	std::unordered_map<Direction, bool> m_collisions; // int = number of overlapping pixels. If 0 -> no collision in that direction
	SystemManager* m_systemManager;
};

