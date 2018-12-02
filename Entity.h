#pragma once
#include <string>
#include <typeinfo> // typeid
#include <typeindex>
#include <unordered_map>
#include <memory>
#include "CTransform.h"
#include "CRender.h"
#include "CInput.h"
#include "CPhysics.h"
#include "CCollider.h"

// One entity is basically a list of components, with no logic nor data in them
class Entity {
public:
	Entity(int l_id);

	int getID() const;
	void setID(int l_id);

	std::string& getName();
	void setName(const std::string& l_name);

	bool isControllable();
	void addComponent(const std::pair<std::type_index, std::shared_ptr<Component>>& l_component);

	// std::shared_ptr<CInput> inputComponent = entity.getComponent<CInput>();
	template <typename T>
	std::shared_ptr<T> getComponent() { // T = CRender, CInput, etc
		if (m_components.find(typeid(T)) != m_components.end()) {
			return std::dynamic_pointer_cast<T>(m_components[typeid(T)]);
		}
		return nullptr;
	}

private:
	int m_id;
	bool m_controllable;
	std::string m_name;
	std::unordered_map<std::type_index, std::shared_ptr<Component>> m_components;
	// TODO: be able to enable/disable components
};