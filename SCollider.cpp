#include "SCollider.h"

SCollider::SCollider(Shared* l_shared) : System(l_shared) {}

/*
Algoritmo de colisiones: al moverse una entidad (SPhysics), se calcula la potencial posici�n en la que estar�. 
Se comprueba si en la nueva posici�n hay intersecci�n con otro rect�ngulo (SCollider). 
Si la hay: si el 2� rect�ngulo es est�tico (no tiene CPhysics), a la entidad que se mueve se le aplican los cambios, restando los X bits superpuestos; 
si el 2� rect�ngulo es din�mico (s� tiene CPhysics), las entidades no pueden moverse en la direcci�n de la colisi�n.
*/

// l_position is an out argument, to be modified in this function if there's an intersection
void SCollider::resolveCollision(std::shared_ptr<CCollider> l_collider, sf::Vector2f& l_position) {
	l_collider->resetCollisions();
	sf::IntRect firstAABB = l_collider->getAABB();
	for (auto& collider2 : m_entitiesCollider) {
		sf::IntRect secondAABB = collider2.second->getAABB();
		if (collider2.second->getAABB() == firstAABB) { continue; }
		if (firstAABB.intersects(secondAABB)) {
			std::cout << firstAABB.left << " " << firstAABB.top << " " << firstAABB.width << " " << firstAABB.height << std::endl;

			int left = abs((firstAABB.left + firstAABB.width) - secondAABB.left);
			int right = abs(firstAABB.left - (secondAABB.left + secondAABB.width));
			int up = abs((firstAABB.top + firstAABB.height) - secondAABB.top);
			int down = abs(firstAABB.top - (secondAABB.top + secondAABB.height));

			if (left < right && left < up && left < down) { // Collider1 to the left of Collider2
				l_collider->setCollision(Direction::Right, left);
				l_position = sf::Vector2f(l_position.x - left + 1, l_position.y);
			}
			if (right < left && right < up && right < down) { // Collider1 to the right of Collider2
				l_collider->setCollision(Direction::Left, right);
				l_position = sf::Vector2f(l_position.x + right - 1, l_position.y);
			}
			if (up < left && up < right && up < down) { // Collider1 below Collider2
				l_collider->setCollision(Direction::Down, up);
				l_position = sf::Vector2f(l_position.x, l_position.y - up + 1);
			}
			if (down < left && down < right && down < up) { // Collider1 above Collider2
				l_collider->setCollision(Direction::Up, down);
				l_position = sf::Vector2f(l_position.x, l_position.y + down - 1);
			}
		}
	}
}

void SCollider::addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CCollider>> l_entity) {
	m_entitiesCollider.emplace(l_entity);
}
