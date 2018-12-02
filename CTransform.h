#pragma once
#include "Component.h"

// Store entity's position (upper left point of entity. Size of entity will rely entirety in CRender's texture's size (32x32, 64x64?)
// CTransform > CRender, CCollider dependencies?
class CTransform : public Component {
public:
	CTransform();

	sf::Vector2f& getPosition();
	void setPosition(const sf::Vector2f& l_position);
	void movePosition(int l_offsetX, int l_offsetY);

	void readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity = nullptr);
private:
	sf::Vector2f m_position;
};

