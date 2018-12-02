#pragma once
#include <memory>
#include "Entity.h"

class Shared;

class System {
public:
	System(Shared* l_shared);
	virtual ~System();
	Shared* getShared() { return m_shared;  }
	
//	virtual void addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<Component>> l_entity) = 0;

protected:
	Shared* m_shared;
};

