#pragma once
#include "Matriz.h"
#include "Ventana.h"

class Menu{
private:
	Ventana* ventana = new Ventana();
	Gato* gato;
public:
	Menu();
	void unJugador();
	void facil();
	void medio();
	void dificil();
	void dosJugadores();
	void dibujaMenuPrincipal();
	void dibujaMenuSecundario();
	int seleccionarMenuPincipal();
	int seleccionarMenuSecundario();
	~Menu();
};