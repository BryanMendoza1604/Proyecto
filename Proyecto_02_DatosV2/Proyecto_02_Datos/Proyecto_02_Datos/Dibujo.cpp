#include "Dibujo.h"

Dibujo::Dibujo(){}

void Dibujo::mostrar(sf::RenderWindow&  v,std::string nom,float x,float y) {
	sf::Texture imagen;
	imagen.loadFromFile(nom);
	sf::Sprite dibujo(imagen);
	dibujo.setPosition(sf::Vector2f(x, y));
	v.draw(dibujo);
}

Dibujo::~Dibujo(){}
