
#include <iostream>
#include "Mapp.h"
#include <conio.h>
#include "Spaceship.h"
#include "Planet.h"

using namespace std;

Spaceship pollo = Spaceship();

Planet::Planet() {

	//
	matrice[pollo.coordinatePlanet(true)][pollo.coordinatePlanet(false)] = 'Y';
}

bool Planet::uscitaDalPlanet(char m) {  
	bool uscita = false;
	if ((pollo.coordinatePlanet(true) == 2))  uscita = true;
	return uscita;
}

void Planet::ripristinaCoordinate() {
	pollo.p3 = 2;
	pollo.p4 = 2;
}




/*void Planet::createSurface() {
	srand((unsigned)time(0));

	int h, n, s;
	bool flag = false;
	while (flag == false) {

		if ((s = (rand() % 25) + 1) >= 10) {
			n = s;							//faccio un primo random e lo metto in n
			matrice[n][0] = '*';
			flag = true;

		}
	}
	for (int i = 1; i < 119; i++) {
		bool guardia = false;
		h = (rand() % 25) + 1;  //faccio un altro random e lo metto in h


		while (guardia == false) {
			if ((n == h - 1 || n == h + 1 || n == h) && h >= 10) {    //Se il random è uguale a quello di prima +1, -1 oppure uguale stampa l'* successivo altrimenti rifà il random
				matrice[h][i] = '*';
				n = h;

				guardia = true;
			}

			else
				h = (rand() % 25) + 1;


		}

	}
}*/

/*void Planet::printPlanet() {  //stampa del pianeta

	//	system("cls");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << matrice[i][j];
		}
		cout << "\n";
	}

}*/