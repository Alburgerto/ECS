#include "EntityManager.h"
#include <filesystem>

EntityManager::EntityManager(SystemManager* l_systemManager) : m_index(0), m_systemManager(l_systemManager) {}

// Creates entities, as well as those components associated to such entities, in the heap, pointed to by shared_ptrs (as they will be owned by more than 1 classes)
// One type of entity per file. Need to iterate through entities folder
void EntityManager::createEntities(const std::string& l_folder) {
	for (const auto& fileName : std::experimental::filesystem::directory_iterator(l_folder)) {
		std::shared_ptr<Entity> entity = std::make_shared<Entity>(m_index++);
		std::shared_ptr<CTransform> transformComponent = std::make_shared<CTransform>(); // Entities will always position
		transformComponent->setPosition(sf::Vector2f(0, 0));
		entity->addComponent(std::pair<std::type_index, std::shared_ptr<CTransform>>(typeid(CTransform), transformComponent));

		std::ifstream file;
		file.open(fileName, std::ifstream::in);
		if (file.bad()) { std::cout << "Could not open file: " << l_folder << std::endl; }

		std::string buffer;
		while (std::getline(file, buffer)) {
			std::string lineType;
			std::stringstream sstream(buffer);
			sstream >> lineType;

			if (lineType == "//" || lineType == "" || (lineType[0] == '/' && lineType[1] == '/')) {
				continue;
			}
			else if (lineType == "Name") {
				std::string name;
				sstream >> name;
				entity->setName(name);
			}
			else { // COMPONENTS
				std::shared_ptr<Component> component;
				auto pair = std::pair<std::shared_ptr<Entity>, std::shared_ptr<Component>>(entity, component);
				std::type_index type = typeid(CTransform);
				if (lineType == "CRender") {
					component = std::make_shared<CRender>();
					type = typeid(CRender);	
					m_systemManager->getRenderSystem()->addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CRender>>(entity, std::dynamic_pointer_cast<CRender>(component)));
				}
				else if (lineType == "CInput") {
					component = std::make_shared<CInput>();
					type = typeid(CInput);
					m_systemManager->getInputSystem()->addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CInput>>(entity, std::dynamic_pointer_cast<CInput>(component)));
				}
				else if (lineType == "CPhysics") {
					component = std::make_shared<CPhysics>();
					type = typeid(CPhysics);
					m_systemManager->getPhysicsSystem()->addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CPhysics>>(entity, std::dynamic_pointer_cast<CPhysics>(component)));
				}
				else if (lineType == "CCollider") {
					component = std::make_shared<CCollider>(m_systemManager);
					type = typeid(CCollider);
					m_systemManager->getColliderSystem()->addEntity(std::pair<std::shared_ptr<Entity>, std::shared_ptr<CCollider>>(entity, std::dynamic_pointer_cast<CCollider>(component)));
				}
				// More components here

				if (lineType == "CTransform") { // Special case, as it was already created
					transformComponent->readComponent(sstream, entity);
				}
				else {
					entity->addComponent(std::pair<std::type_index, std::shared_ptr<Component>>(type, component));
					component->readComponent(sstream, entity);
				}
			}
		}
		file.close();
	}
}