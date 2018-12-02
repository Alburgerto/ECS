#pragma once
#include "Component.h"

// Holds information about visible entities: texture to render + position of render
class CRender : public Component {
public:
	CRender();
	sf::Sprite& getSprite();
	void readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity = nullptr);

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;

};

