#pragma once
#include <vector>
#include <memory>
#include <unordered_map>
#include "System.h"

// Only responsable for drawing sprites. In the future an animation system will update any drawable entity's sprite, as they will be composed of a handful of them
class SRender : System {
public:
	SRender(Shared* l_shared);
	void update(sf::RenderWindow* l_window);
	void addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CRender>> l_entity);
	void addDebugAABB(sf::RectangleShape* l_collider);

private:
	std::unordered_map<std::shared_ptr<Entity>, std::shared_ptr<CRender>> m_entitiesRender;
	std::vector<sf::RectangleShape*> m_debugAABB;
};

