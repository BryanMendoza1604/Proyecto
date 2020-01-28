#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Ventana{
private:
	void setup(const std::string _titulo, const sf::Vector2u& _tam);
	void crear();
	void cerrar();

	sf::RenderWindow ventana;
	sf::Vector2u tamano;
	std::string titulo;

	bool m_isDone;
	bool pantallaCompleta;

public:
	Ventana();

	Ventana(const std::string& title, const sf::Vector2u& size);

	void empiezaDibujar();

	void terminaDibujar();

	void actualizar();

	bool IsDone();

	void alternarPantallaCompleta();

	sf::RenderWindow* getVentana();
	sf::Vector2u getTamano();

	~Ventana();
};