#pragma once
#include "Entity.h"
#include <string>
#include <sstream>
#include <memory>
#include <fstream>
#include "SystemManager.h"

// For now it only creates all entities reading files from the project's assets folder, keeps a pointer to all of them
class EntityManager {
public:
	EntityManager(SystemManager* l_renderSystem);
	void createEntities(const std::string& l_file);

private:
	int m_index;
	SystemManager* m_systemManager;
};

