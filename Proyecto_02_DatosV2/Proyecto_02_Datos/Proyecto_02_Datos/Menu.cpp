#include "Menu.h"

Menu::Menu(){
	while (!ventana->IsDone()) {
		ventana->actualizar();
		ventana->empiezaDibujar();

		dibujaMenuPrincipal();
		int opc = seleccionarMenuPincipal();
		if (opc == 3) {
			break;
		}

			switch (opc) {
			case 1:
				unJugador();
				break;
			case 2:
				dosJugadores();
				break;
			default:
				break;
			}

		ventana->terminaDibujar();
	}
	
}

void Menu::unJugador() {
	while (!ventana->IsDone()) {
		ventana->actualizar();
		ventana->empiezaDibujar();
		dibujaMenuSecundario();
		int opc = seleccionarMenuSecundario();
		if (opc == 4) {
			break;
		}
			switch (opc) {
			case 1:
				facil();
				break;
			case 2:
				medio();
				break;
			case 3:
				dificil();
				break;
			default:
				break;
			}
		ventana->terminaDibujar();
	}
}

void Menu::facil() {
	gato = new Gato;
	while (!ventana->IsDone()) {
		ventana->actualizar();
		ventana->empiezaDibujar();

		gato->mostrarMatriz(*ventana->getVentana());
		if (gato->estaLleno() || gato->hayGanador() == 1 || gato->hayGanador() == 2) {
			gato->mostrarMatriz(*ventana->getVentana());
			break;
		}
		if (gato->hayGanador() == 3) {
			gato->facil(*ventana->getVentana());
		}

		ventana->terminaDibujar();
	}
	delete gato;
	std::cout << "facil\n";
}
void Menu::medio() {
	gato = new Gato;
	while (!ventana->IsDone()) {
		ventana->actualizar();
		ventana->empiezaDibujar();

		gato->mostrarMatriz(*ventana->getVentana());
		if (gato->estaLleno() || gato->hayGanador() == 1 || gato->hayGanador() == 2) {
			gato->mostrarMatriz(*ventana->getVentana());
			break;
		}
		if (gato->hayGanador() == 3) {
			gato->medio(*ventana->getVentana());
		}

		ventana->terminaDibujar();
	}
	delete gato;
	std::cout << "medio\n";
}
void Menu::dificil() {
	std::cout << "dificil\n";
}

void Menu::dosJugadores() {
	gato = new Gato;
	while (!ventana->IsDone()) {
		ventana->actualizar();
		ventana->empiezaDibujar();

		gato->mostrarMatriz(*ventana->getVentana());
		if (gato->estaLleno()|| gato->hayGanador() == 1||gato->hayGanador() == 2) {
			break;
		}
		if (gato->hayGanador() == 3) {
			gato->insertarElem(*ventana->getVentana());
		}

		ventana->terminaDibujar();
	}
	delete gato;
}

void Menu::dibujaMenuPrincipal() {
	Dibujo d;
	d.mostrar(*ventana->getVentana(), "TicTacToe.png", 25, 25);
	d.mostrar(*ventana->getVentana(), "pvp.jpg", 50, 150);
	d.mostrar(*ventana->getVentana(), "pvpc.jpg", 50, 225);
	d.mostrar(*ventana->getVentana(), "salir.jpg", 50, 300);
}

void Menu::dibujaMenuSecundario() {
	Dibujo d;
	d.mostrar(*ventana->getVentana(), "facil.jpg", 75, 10);
	d.mostrar(*ventana->getVentana(), "medio.jpg",75 , 107);
	d.mostrar(*ventana->getVentana(), "dificil.jpg", 75, 204);
	d.mostrar(*ventana->getVentana(), "volver.jpg", 75, 301);
}

int Menu::seleccionarMenuPincipal() {
	sf::Event event1;
	int x, y;
	(*ventana->getVentana()).pollEvent(event1);
	
	if (event1.type == sf::Event::MouseButtonPressed) {
		if (event1.mouseButton.button == sf::Mouse::Left) {
			x = event1.mouseButton.x;
			y = event1.mouseButton.y;

			if (x > 50 && x < 350) {
				if (y > 150 && y < 200) {
					return 2;
				}
				else {
					if (y > 225 && y < 275) {
						return 1;
					}
					else {
						if (y > 300 && y < 350) {
							return 3;
						}
					}
				}
			}
		}
	}
	event1.Closed;
}

int Menu::seleccionarMenuSecundario() {
	sf::Event event1;
	int x, y;
	(*ventana->getVentana()).pollEvent(event1);

	if (event1.type == sf::Event::MouseButtonPressed) {
		if (event1.mouseButton.button == sf::Mouse::Left) {
			x = event1.mouseButton.x;
			y = event1.mouseButton.y;

			if (x > 75 && x < 325) {
				if (y > 10 && y < 97) {
					return 1;
				}
				else {
					if (y > 107 && y < 194) {
						return 2;
					}
					else {
						if (y > 204 && y < 291) {
							return 3;
						}
						else {
							if (y > 301 && y < 388) {
								return 4;
							}
						}
					}
				}
			}
		}
		
	}
	event1.Closed;
}

Menu::~Menu(){}
