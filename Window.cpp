#include "Window.h"

Window::Window() { setup("Window", sf::Vector2u(640, 480)); }
Window::Window(const std::string& title, const sf::Vector2u& size) { setup(title, size); }
Window::~Window() { destroy(); }
void Window::setup(const std::string& title, const sf::Vector2u& size) {
	m_isFocused = true;
	m_title = title;
	m_size = size;
	m_isFullscreen = false;
	m_isDone = false;
	create();
}

void Window::create() {
	sf::Uint32 style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.create({ m_size.x, m_size.y, 32 }, m_title, style);
}
void Window::destroy() { m_window.close(); }

void Window::beginDraw() { m_window.clear(sf::Color::Black); }
void Window::endDraw() { m_window.display(); }
void Window::draw(sf::Drawable& l_drawable) { m_window.draw(l_drawable); }

bool Window::isFocused() {
	return m_isFocused;
}

void Window::close() {
	m_isDone = true;
}

void Window::update() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		if (event.type == sf::Event::LostFocus) {
			m_isFocused = false;
		}
		else if (event.type == sf::Event::GainedFocus) {
			m_isFocused = true;
		}
	}
}

sf::RenderWindow* Window::getRenderWindow() { return &m_window; }

void Window::toggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	destroy();
	create();
}

bool Window::isDone() const { return m_isDone; }

bool Window::isFullscreen() const { return m_isFullscreen; }

sf::Vector2u Window::getSize() const { return m_size; }

sf::FloatRect Window::getViewSpace() {
	sf::Vector2f size = m_window.getView().getSize();
	sf::Vector2f center = m_window.getView().getCenter();
	sf::Vector2f topLeft = sf::Vector2f(center.x - size.x / 2, center.y - size.y / 2);
	return sf::FloatRect(topLeft, size);
}