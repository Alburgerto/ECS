#include "State_Pause.h"
#include "Shared.h"


State_Pause::State_Pause(Shared* l_shared) : BaseState(l_shared), m_chosenOption(0) {
	if (!m_font.loadFromFile("Assets/Fonts/KarmaFuture.ttf")) {
		std::cerr << "Could not load font" << std::endl;
	}

	m_options.at(0).setString("Resume");
	m_options.at(1).setString("Go to menu");

	for (int i = 0; i < m_options.size(); ++i) {
		m_options.at(i).setFont(m_font);
		m_options.at(i).setCharacterSize(30);
		m_options.at(i).setFillColor(sf::Color::Black);
		m_options.at(i).setOrigin(m_options.at(i).getLocalBounds().left + m_options.at(i).getLocalBounds().width / 2, m_options.at(i).getLocalBounds().top + m_options.at(i).getLocalBounds().height / 2);
		m_options.at(i).setPosition(350, 250 + i * 50);
	}
	m_options.at(0).setFillColor(sf::Color::Blue);
}

void State_Pause::input() {
	sf::Event event;
	while (m_shared->m_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_shared->m_window->close();
		}
		else if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::Z)) {
			changeState();
		}
		else if (event.key.code == sf::Keyboard::Up) {
			if (m_chosenOption > 0) {
				m_options.at(m_chosenOption).setFillColor(sf::Color::Black);
				m_options.at(--m_chosenOption).setFillColor(sf::Color::Blue);
			}
		}
		else if (event.key.code == sf::Keyboard::Down) {
			if (m_chosenOption < (m_options.size() - 1)) {
				m_options.at(m_chosenOption).setFillColor(sf::Color::Black);
				m_options.at(++m_chosenOption).setFillColor(sf::Color::Blue);
			}
		}
	}
}

void State_Pause::changeState() {
	if (m_chosenOption == 0) {
		m_shared->m_stateManager->changeState(StateType::Game);
	}
	else {
		// TODO: delete progress made in game
		m_shared->m_stateManager->changeState(StateType::Menu);
	}
}

void State_Pause::enable() {
	m_chosenOption = 0;
	m_options.at(0).setFillColor(sf::Color::Blue);
	m_options.at(1).setFillColor(sf::Color::Black);
}

void State_Pause::draw(float l_dT) {
	m_shared->m_window->clear(sf::Color::Red);

	for (int i = 0; i < m_options.size(); ++i) {
		m_shared->m_window->draw(m_options.at(i));
	}

	m_shared->m_window->display();
}

void State_Pause::update(float l_dT) {
	input();
	draw(l_dT);
}
