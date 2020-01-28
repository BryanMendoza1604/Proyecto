#include "Ventana.h"

Ventana::Ventana() { setup("Tic Tac Toe", sf::Vector2u(402, 402)); }
Ventana::Ventana(const std::string& _titulo, const sf::Vector2u& _tam) { setup(_titulo, _tam); }

void Ventana::setup(const std::string _titulo, const sf::Vector2u& _tam) {
	titulo = _titulo;
	tamano = _tam;
	pantallaCompleta = false;
	m_isDone = false;
	crear();
}

void Ventana::crear() {
	auto style = (pantallaCompleta ? sf::Style::Fullscreen
		: sf::Style::Default);
	ventana.create({ tamano.x, tamano.y, 32 },titulo, style);
}

void Ventana::cerrar() {
	ventana.close();
}

sf::RenderWindow* Ventana::getVentana() { return &ventana; }
sf::Vector2u Ventana::getTamano() { return tamano; }

bool Ventana::IsDone() { return m_isDone; }
void Ventana::empiezaDibujar() { ventana.clear(sf::Color::White); }
void Ventana::terminaDibujar() { ventana.display(); }

void Ventana::alternarPantallaCompleta() {
	pantallaCompleta = !pantallaCompleta;
	ventana.close();
	crear();
}

void Ventana::actualizar() {
	sf::Event event;
	while (ventana.pollEvent(event)) {
		if (event.type == sf::Event::Closed) { m_isDone = true; }
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) { m_isDone = true; }
		else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5) { alternarPantallaCompleta(); }
	}
}

Ventana::~Ventana() { cerrar(); }