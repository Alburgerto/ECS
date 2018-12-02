#pragma once
#include <unordered_map>
#include <iterator>
#include "System.h"

// Manages collisions between intersecting CColliders
class SCollider : System {
public:
	SCollider(Shared* l_shared);

	void resolveCollision(std::shared_ptr<CCollider> l_collider, sf::Vector2f& l_position);
	void addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CCollider>> l_entity);
	
private:
	std::unordered_map<std::shared_ptr<Entity>, std::shared_ptr<CCollider>> m_entitiesCollider;
};

