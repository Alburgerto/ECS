#include "SPhysics.h"
#include "SInput.h" // Need to forward declare here to access Actions enum
#include "Shared.h"

SPhysics::SPhysics(Shared* l_shared) : System(l_shared) {}

// apply velocity, check collisions, friction...
void SPhysics::update(float l_dT) {
	for (auto& entity : m_entitiesPhysics) {
		entity.second->setVelocity({ 0, 0 });
		if (entity.first->isControllable()) { // Player -> input
			// Need to access CInput to check on input flags -> then update CPhysics' velocity + CRender's sprite position
			sf::Vector2i newVelocity(0, 0);
			std::shared_ptr<CInput> inputComponent = entity.first->getComponent<CInput>();
			std::shared_ptr<CCollider> colliderComponent = entity.first->getComponent<CCollider>();
			if (inputComponent->getAction(Actions::MoveLeft) && !colliderComponent->getCollision(Direction::Left)) {
				newVelocity += {-1, 0};
			}
			if (inputComponent->getAction(Actions::MoveRight) && !colliderComponent->getCollision(Direction::Right)) {
				newVelocity += {1, 0};
			}
			if (inputComponent->getAction(Actions::MoveUp) && !colliderComponent->getCollision(Direction::Up)) {
				newVelocity += {0, -1};
			}
			if (inputComponent->getAction(Actions::MoveDown) && !colliderComponent->getCollision(Direction::Down)) {
				newVelocity += {0, 1};
			}
			entity.second->setVelocity(newVelocity);
			sf::Vector2i finalVelocity = entity.second->getVelocity();

			std::shared_ptr<CTransform> transformComponent = entity.first->getComponent<CTransform>();
			sf::Vector2f previousPosition = transformComponent->getPosition();
			sf::Vector2f newPosition = sf::Vector2f(previousPosition.x + finalVelocity.x * l_dT, previousPosition.y + finalVelocity.y * l_dT);
			
			// Collision detection/management
			m_shared->m_systemManager->getColliderSystem()->resolveCollision(colliderComponent, newPosition); // newPosition altered to avoid overlapping pixels

			transformComponent->setPosition(newPosition);
			std::shared_ptr<CRender> renderComponent = entity.first->getComponent<CRender>();
			renderComponent->getSprite().setPosition(sf::Vector2f(newPosition));
			colliderComponent->setPosition(newPosition);
			newVelocity = { 0, 0 };
		}
		else { // AI -> AI system sets path points for NPC to follow

		}
	}

}

void SPhysics::addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CPhysics>> l_entity) {
	m_entitiesPhysics.emplace(l_entity);
}


