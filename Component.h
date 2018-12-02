#pragma once
#include <SFML\Graphics.hpp>
#include <unordered_map>
#include <iostream>
#include <sstream>

class Entity;

// All info about entities are stored into components. An entity is only an id + an aggregation of components
// Need Component class to have list/vector/map of Component polymorphic objects
// Also need pure virtual function to parse each component

class Component {
public:
	Component();
	virtual ~Component();
	virtual void readComponent(std::stringstream& l_data, std::shared_ptr<Entity> l_entity = nullptr) = 0;
};

