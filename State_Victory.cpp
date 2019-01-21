#include "State_Victory.h"
#include "Shared.h"


State_Victory::State_Victory(Shared* l_shared) : BaseState(l_shared) {
	if (!m_font.loadFromFile("Assets/Fonts/KarmaFuture.ttf")) {
		std::cerr << "Could not load font" << std::endl;
	}

	m_options.at(0).setString("Congrats! You win!");
	m_options.at(1).setString("Press Enter to go back to the menu");

	for (int i = 0; i < m_options.size(); ++i) {
		m_options.at(i).setFont(m_font);
		m_options.at(i).setCharacterSize(30);
		m_options.at(i).setOrigin(m_options.at(i).getLocalBounds().left + m_options.at(i).getLocalBounds().width / 2, m_options.at(i).getLocalBounds().top + m_options.at(i).getLocalBounds().height / 2);
		m_options.at(i).setPosition(350, 150 + i * 100);
	}
	m_options.at(0).setFillColor(sf::Color::Black);
	m_options.at(1).setFillColor(sf::Color::Blue);
}

void State_Victory::input() {
	sf::Event event;
	while (m_shared->m_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_shared->m_window->close();
		}
		else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Z)) {
			changeState();
		}
	}
}

void State_Victory::draw(float l_d) {
	m_shared->m_window->clear(sf::Color::Red);

	for (int i = 0; i < m_options.size(); ++i) {
		m_shared->m_window->draw(m_options.at(i));
	}

	m_shared->m_window->display();
}

void State_Victory::update(float l_dT) {
	input();
	draw(l_dT);
}

void State_Victory::changeState() {
	m_shared->m_stateManager->changeState(StateType::Menu);
}

void State_Victory::enable() {

}
