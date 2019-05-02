#include <iostream>
#include "Mapp.h"
#include <conio.h>
#include "Spaceship.h"
using namespace std;


Spaceship navi = Spaceship();

//crea la matrice (mappa) di char con spazi tutti vuoti e setta i bordi con dei caratteri (puntini)
Mapp::Mapp()
{
	x = 20;
	y = 80;

	for (int z = 0; z < x; z++) {
		for (int j = 0; j < y; j++) {
			matrice[z][j] = ' ';
		}
	}

	int i;
	for (i = 0; i < x; i++)  matrice[i][0] = ':';
	for (i = 0; i < x; i++)  matrice[i][y - 1] = ':';
	for (i = 0; i < y; i++)  matrice[0][i] = '.';
	for (i = 0; i < y; i++)  matrice[x - 1][i] = '.';
	matrice[navi.coordinate(true)][navi.coordinate(false)] = 'Y';
}



//setta da carattere nullo a carattere "Y" la nuova posizione della navicellaù
//setta anche le quattro posizioni adiacenti in carattere nullo (cancellando la vecchia posizione)
//prima di settare fa un controllo per vedere se è vicino ad un bordo della mappa, in tal caso non modifica il carattere in prossimita del relativo margine
bool Mapp::setMatrice(int x, int y, char n) {

	bool guardia = false;

	if (n == 75 && y > 0) {       //left
		if (matrice[x][y] != 'O') {
			matrice[x][y + 1] = ' ';
			matrice[x][y] = 'Y';
		}
		else guardia = true;
	}

	else if (n == 77 && y < 79) { //righ
		if (matrice[x][y] != 'O') {
			matrice[x][y - 1] = ' ';
			matrice[x][y] = 'Y';
		}
		else guardia = true;
	}

	else if (n == 72 && x > 0) {    //up
		if (matrice[x][y] != 'O') {
			matrice[x][y] = 'Y';
			matrice[x + 1][y] = ' ';
		}
		else guardia = true;
	}

	else if (n == 80 && x < 20) {    //down
		if (matrice[x][y] != 'O') {
			matrice[x - 1][y] = ' ';
			matrice[x][y] = 'Y';
		}
		else guardia = true;
	}

	return guardia;
}


//while "infinito" che stampa la mappa
void Mapp::printMapp() {

	system("cls");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << matrice[i][j];
		}
		cout << "\n";
	}

}