#include "CRender.h"
#include "Entity.h"

CRender::CRender() {}

sf::Sprite& CRender::getSprite() {
	return m_sprite;
}

void CRender::readComponent(std::stringstream& l_line, std::shared_ptr<Entity> l_entity) {
	std::string filePath;
	l_line >> filePath;
	// Arguments will change in the future, when instead of a single sprite, there's a spritesheet, which will probably be held @ a TextureManager
	if (!m_texture.loadFromFile(filePath)) {
		std::cout << "Could not load texture from file: " << filePath << std::endl;
	}
	m_sprite.setTexture(m_texture);
	m_sprite.setPosition(l_entity->getComponent<CTransform>()->getPosition());
}
