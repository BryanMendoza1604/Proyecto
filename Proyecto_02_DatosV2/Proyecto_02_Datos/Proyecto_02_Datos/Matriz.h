#pragma once
#include "Dibujo.h"
#include <iostream>
#include <time.h>

class Gato {
private:
	char** m;
	int col;
	int fil;
public:
	Gato();
	int hayGanador();
	bool estaLleno();
	void insertarElem(sf::RenderWindow&);
	std::string dibuja(char);
	void facil(sf::RenderWindow&);
	void medio(sf::RenderWindow&);
	void mostrarMatriz(sf::RenderWindow&);
	~Gato();
};