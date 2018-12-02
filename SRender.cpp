#include "SRender.h"

SRender::SRender(Shared* l_shared) : System(l_shared) {}

void SRender::update(sf::RenderWindow* l_window) {
	l_window->clear(sf::Color::Red);
	for (auto &entity : m_entitiesRender) { // TODO filter entities to draw only those within screen boundaries, taking into consideration Z-order to draw in the right order
		l_window->draw(entity.second->getSprite());
	}
	for (auto &aabb : m_debugAABB) {
		std::cout << aabb->getPosition().x << " " << aabb->getPosition().y << " " << aabb->getSize().x << " " << aabb->getSize().y << std::endl;

		l_window->draw(*aabb);
	}
	l_window->display();
}

void SRender::addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CRender>> l_entity) {
	m_entitiesRender.emplace(l_entity);
}

void SRender::addDebugAABB(sf::RectangleShape* l_collider) {
	m_debugAABB.emplace_back(l_collider);
}
