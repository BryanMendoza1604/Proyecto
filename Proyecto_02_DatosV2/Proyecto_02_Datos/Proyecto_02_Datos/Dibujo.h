#pragma once
#include "Ventana.h"

class Dibujo{
public:
	Dibujo();
	void mostrar(sf::RenderWindow&,std::string,float ,float);
	~Dibujo();
};