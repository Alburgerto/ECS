#include "Entity.h"

Entity::Entity(int l_id) : m_id(l_id), m_controllable(false) {}

int Entity::getID() const {
	return m_id;
}

void Entity::setID(int l_id) {
	m_id = l_id;
}

std::string& Entity::getName() {
	return m_name;
}

void Entity::setName(const std::string& l_name) {
	m_name = l_name;
}

bool Entity::isControllable() {
	return m_controllable;
}

void Entity::addComponent(const std::pair<std::type_index, std::shared_ptr<Component>>& l_component) {
	if (!m_components.insert(l_component).second) {
		std::cerr << "Duplicated component in entity: " << m_name << std::endl;
		// Debbuging purposes
		if (l_component.first == typeid(CRender)) {
			std::cout << "RENDER" << std::endl;
		} else if (l_component.first == typeid(CTransform)) {
			std::cout << "TRANSFORM" << std::endl;
		}
		else if (l_component.first == typeid(CPhysics)) {
			std::cout << "PHYSICS" << std::endl;
		}
		else if (l_component.first == typeid(CInput)) {
			std::cout << "CInput" << std::endl;
		}
		else if (l_component.first == typeid(CCollider)) {
			std::cout << "COLLIDER" << std::endl;
		}
	}
	if (!m_controllable && l_component.first == typeid(CInput)) {
		m_controllable = true;
	}
}
