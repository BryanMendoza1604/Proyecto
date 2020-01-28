#include "Matriz.h"

Gato::Gato(): fil(3),col(3){
	m = new char*[fil];
	for (int i = 0; i < fil; i++) {
		m[i] = new char[col];
	}

	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			m[i][j] = ' ';
		}
	}
}

bool Gato::estaLleno() {
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			if (m[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

void Gato::insertarElem( sf::RenderWindow& ventana) {
	sf::Event event1;

	int x, y;

	ventana.pollEvent(event1);
	char elem;
	if (event1.type == sf::Event::MouseButtonPressed){
		if (event1.mouseButton.button == sf::Mouse::Right) {
			elem = 'X';
		}
		else {
			if (event1.mouseButton.button == sf::Mouse::Left) {
				elem = 'O';
			}
		}
		x = event1.mouseButton.x;
		y = event1.mouseButton.y;
			if (y < 134) {
				if (x < 134) {
					if(m[0][0]==' ')
					m[0][0] = elem;
				}
				else {
					if (x < 268) {
						if (m[0][1] == ' ')
						m[0][1] = elem;
					}
					else {
						if (m[0][2] == ' ')
						m[0][2] = elem;
					}
				}
			}
			else {
				if (y < 268) {
					if (x < 134) {
						if (m[1][0] == ' ')
						m[1][0] = elem;
					}
					else {
						if (x < 268) {
							if (m[1][1] == ' ')
							m[1][1] = elem;
						}
						else {
							if (m[1][2] == ' ')
							m[1][2] = elem;
						}
					}
				}
				else {
					if (x < 134) {
						if (m[2][0] == ' ')
						m[2][0] = elem;
					}
					else {
						if (x < 268) {
							if (m[2][1] == ' ')
							m[2][1] = elem;
						}
						else {
							if (m[2][2] == ' ')
							m[2][2] = elem;
						}
					}
				}
			}
		}
	event1.Closed;
}

int Gato::hayGanador(){
	int contX = 0;
	int contO = 0;

	int j = 2;
	for (int i = 0; i < col; i++) {
			if (m[i][j] == 'X') {
				contX++;
			}
			if (m[i][j] == 'O') {
				contO++;
			}
			j--;
	}

	if (contX == 3)
		return 1;
	if (contO == 3)
		return 2;

	contX = 0;
	contO = 0;

	for (int i = 0; i < fil; i++) {
		if (m[i][i] == 'X')
			contX++;
		if (m[i][i] == 'O')
			contO++;
	}
	if (contX == 3)
		return 1;
	if (contO == 3)
		return 2;

	for (int i = 0; i < fil; i++) {
		int cont1 = 0;
		int cont2 = 0;
		for (int j = 0; j < col; j++) {
			if (m[i][j] == 'X')
				cont1++;
			if (m[i][j] == 'O')
				cont2++;
		}
		if (cont1 == 3)
			return 1;
		if (cont2 == 3)
			return 2;
	}

	for (int i = 0; i < fil; i++) {
		int cont1 = 0;
		int cont2 = 0;
		for (int j = 0; j < col; j++) {
			if (m[j][i] == 'X')
				cont1++;
			if (m[j][i] == 'O')
				cont2++;
		}
		if (cont1 == 3)
			return 1;
		if (cont2 == 3)
			return 2;
	}

	if (estaLleno() == true) {
		return 0;
	}
	else {
		return 3;
	}
}

void Gato::mostrarMatriz(sf::RenderWindow&  v) {
	Dibujo d;
	float x = 0, y = 0;

	for (int i = 0; i < fil; i++) {
		x = 0;
		for (int j = 0; j < col; j++) {
			d.mostrar(v, dibuja(m[i][j]), x, y);
			std::cout << "[" << m[i][j] << "]";
			x += 134;
		}
		std::cout << "\n";
		y += 134;
	}
}

std::string Gato::dibuja(char dato) {
	if (dato == ' ') {
		return "blanco.png";
	}
	else {
		if (dato == 'X') {
			return "equis.png";
		}
		else {
			if (dato == 'O') {
				return "circulo.png";
			}
		}
	}
}

void Gato::facil(sf::RenderWindow&  ventana) {

	sf::Event event1;

	int x, y;

	ventana.pollEvent(event1);
	char elem;
	bool hizoMovimineto = false;
		if (event1.type == sf::Event::MouseButtonPressed) {
			if (event1.mouseButton.button == sf::Mouse::Left) {
				elem = 'O';
			}
			else {
				return;
			}
			x = event1.mouseButton.x;
			y = event1.mouseButton.y;
			if (y < 134) {
				if (x < 134) {
					if (m[0][0] == ' ') {
						m[0][0] = elem;
						hizoMovimineto = true;
					}
				}
				else {
					if (x < 268) {
						if (m[0][1] == ' ') {
							m[0][1] = elem;
							hizoMovimineto = true;
						}
					}
					else {
						if (m[0][2] == ' ') {
							m[0][2] = elem;
							hizoMovimineto = true;
						}
					}
				}
			}
			else {
				if (y < 268) {
					if (x < 134) {
						if (m[1][0] == ' ') {
							m[1][0] = elem;
							hizoMovimineto = true;
						}
					}
					else {
						if (x < 268) {
							if (m[1][1] == ' ') {
								m[1][1] = elem;
								hizoMovimineto = true;
							}
						}
						else {
							if (m[1][2] == ' ') {
								m[1][2] = elem;
								hizoMovimineto = true;
							}
						}
					}
				}
				else {
					if (x < 134) {
						if (m[2][0] == ' ') {
							m[2][0] = elem;
							hizoMovimineto = true;
						}
					}
					else {
						if (x < 268) {
							if (m[2][1] == ' ') {
								m[2][1] = elem;
								hizoMovimineto = true;
							}
						}
						else {
							if (m[2][2] == ' ') {
								m[2][2] = elem;
								hizoMovimineto = true;
							}
						}
					}
				}
			}
			if (!estaLleno() && hizoMovimineto == true) {
				srand(time(nullptr));
				int i = rand() % 3;
				int j = rand() % 3;
				
				while (m[i][j] != ' ') {
					
					i = rand() % 3;
					j = rand() % 3;
				}

				m[i][j] = 'X';
			}
		}
		

		
	event1.Closed;
}

void Gato::medio(sf::RenderWindow& ventana) {
	
	sf::Event event1;

	int x, y;

	ventana.pollEvent(event1);

	char elem;

	bool hizoMovimiento = false;

	if (event1.type == sf::Event::MouseButtonPressed) {
		if (event1.mouseButton.button == sf::Mouse::Left) {
			elem = 'O';
		}
		else
			return;

		x = event1.mouseButton.x;
		y = event1.mouseButton.y;

		if (y < 134) {
			if (x < 134) {
				if (m[0][0] == ' ') {
					m[0][0] = elem;
					hizoMovimiento = true;
				}
			}
			else {
				if (x < 268) {
					if (m[0][1] == ' ') {
						m[0][1] = elem;
						hizoMovimiento = true;
					}
				}
				else {
					if (m[0][2] == ' ') {
						m[0][2] = elem;
						hizoMovimiento = true;
					}
				}
			}
		}
		else {
			if (y < 268) {
				if (x < 134) {
					if (m[1][0] == ' ') {
						m[1][0] = elem;
						hizoMovimiento = true;
					}
				}
				else {
					if (x < 268) {
						if (m[1][1] == ' ') {
							m[1][1] = elem;
							hizoMovimiento = true;
						}
					}
					else {
						if (m[1][2] == ' ') {
							m[1][2] = elem;
							hizoMovimiento = true;
						}
					}
				}
			}
			else {
				if (x < 134) {
					if (m[2][0] == ' ') {
						m[2][0] = elem;
						hizoMovimiento = true;
					}
				}
				else {
					if (x < 268) {
						if (m[2][1] == ' ') {
							m[2][1] = elem;
							hizoMovimiento = true;
						}
					}
					else {
						if (m[2][2] == ' ') {
							m[2][2] = elem;
							hizoMovimiento = true;
						}
					}
				}
			}
		}

		if (!estaLleno() && hizoMovimiento == true) {
			srand(time(nullptr));
			int i = rand() % 3;
			int j = rand() % 3;

			while (m[i][j] != ' ') {

				i = rand() % 3;
				j = rand() % 3;
			}

			if (m[1][1] == 'O') {
				if (m[0][1] == 'O' && m[2][1] == ' ')
					m[2][1] = 'X';

				else if (m[2][1] == 'O' && m[0][1] == ' ')
					m[0][1] = 'X';

				else if (m[1][2] == 'O' && m[1][0] == ' ')
					m[1][0] = 'X';

				else if (m[1][0] == 'O' && m[1][2] == ' ')
					m[1][2] = 'X';

				else if (m[0][2] == 'O' && m[2][0] == ' ')
					m[2][0] = 'X';

				else if (m[2][0] == 'O' && m[0][2] == ' ')
					m[0][2] = 'X';

				else if (m[0][0] == 'O' && m[2][2] == ' ')
					m[2][2] = 'X';

				else
					m[i][j] = 'X';
			}

			else if (m[0][0] == 'O') {
				if (m[0][1] == 'O' && m[0][2] == ' ')
					m[0][2] = 'X';

				else if (m[1][1] == 'O' && m[2][2] == ' ')
					m[2][2] = 'X';

				else if (m[1][0] == 'O' && m[2][0] == ' ')
					m[2][0] = 'X';

				else
					m[i][j] = 'X';
			}

			else if (m[0][2] == 'O') {
				if (m[0][1] == 'O' && m[0][0] == ' ')
					m[0][0] = 'X';

				else if (m[1][1] == 'O' && m[2][0] == ' ')
					m[2][0] = 'X';

				else if (m[1][2] == 'O' && m[2][2] == ' ')
					m[2][2] = 'X';

				else
					m[i][j] = 'X';
			}

			else if (m[2][2] == 'O') {
				if (m[1][2] == 'O' && m[0][2] == ' ')
					m[0][2] = 'X';

				else if (m[1][1] == 'O' && m[0][0] == ' ')
					m[0][0] = 'X';

				else if (m[2][1] == 'O' && m[2][0] == ' ')
					m[2][0] = 'X';

				else
					m[i][j] = 'X';
			}

			else if (m[2][0] == 'O')
				m[i][j] = 'X';

			else if (m[0][1] == 'O')
				m[i][j] = 'X';

			else if (m[1][2] == 'O')
				m[i][j] = 'X';

			else if (m[2][1] == 'O')
				m[i][j] = 'X';

			else if (m[1][0] == 'O')
				m[i][j] = 'X';

			else
				m[i][j] == 'X';
		}
	}
}



Gato::~Gato() {
	for (int i = 0; i < fil; i++) {
			delete[] m[i];
	}
	m = nullptr;
	delete[] m;
	
}