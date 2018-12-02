#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// Not used as of now, might do in the future if I need a more sophisticated game window
class Window {
public:
	Window();
	Window(const std::string& title, const sf::Vector2u& size);
	~Window();

	void beginDraw();
	void endDraw();
	void draw(sf::Drawable& l_drawable);

	void update();
	sf::RenderWindow* getRenderWindow();

	bool isFocused();
	void toggleFullscreen();
	void close();

	bool isDone() const;
	bool isFullscreen() const;
	sf::Vector2u getSize() const;
	sf::FloatRect getViewSpace();
private:
	void setup(const std::string& title, const sf::Vector2u& size);
	void create();
	void destroy();

	sf::RenderWindow m_window;
	sf::Vector2u m_size;
	std::string m_title;

	bool m_isFocused;
	bool m_isFullscreen;
	bool m_isDone;
};