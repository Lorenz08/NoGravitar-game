#include <iostream>
#include <conio.h>
#include <ctime>
#include "windows.h"
#include "Spaceship.h"
#include "Planet.h"
#include "Infinito.h"

using namespace std;


Planet::Planet() {
	//setta cornice
	for (int z = 0; z < x; z++) {
		for (int j = 0; j < y; j++) {
			matrice[z][j] = ' ';
		}
	}
	int i;
	matrice[0][0] = 201;
	matrice[19][0] = 200;
	matrice[0][79] = 187;
	matrice[19][79] = 188;
	for (i = 1; i < x-1; i++)  matrice[i][0] = 186;
	for (i = 1; i < x-1; i++)  matrice[i][y - 1] = 186;
	for (i = 1; i < y-1; i++)  matrice[0][i] = 205;
	for (i = 1; i < y-1; i++)  matrice[x - 1][i] = 205;



	//setta la posizione del primo '*' che va a formare la superfice del pianeta (da 10 a 16)
	int valorePrecedente = ((rand() % 7) + 10); 

	//valore successivo, serivirà poi per fare il confronto con valorePrcedente per formare una superfice 
	//dove lo scostamento tra un '*' e l'altro è solo di 1
	int valoreSuccessivo = 0; 
	

	//imposta il limite superiore del primo '*' (minimo 10, massimo 16)
	//matrice[valorePrecedente][1] = 238;

	//setta il resto della superfice facendo dei confronti per avere uno scostamento (negativo o positivo) massimo di 1
	i = 1;
	while (i <= 78) {
		valoreSuccessivo = (rand() % 16) + 1;

		if ((valoreSuccessivo == valorePrecedente - 1) && (valoreSuccessivo >= 10)) {
			matrice[valoreSuccessivo][i] = '/';
			//if (i != 78) matrice[valoreSuccessivo][i + 1] = 238;
			valorePrecedente = valoreSuccessivo;
			i = i + 1;
		}
		else if ((valoreSuccessivo == valorePrecedente + 1) && (valoreSuccessivo >= 10)) {
			matrice[valoreSuccessivo-1][i] = 92;
			//if (i != 78) matrice[valoreSuccessivo][i + 1] = 238;
			valorePrecedente = valoreSuccessivo;
			i = i + 1;
		}
		else if ((valoreSuccessivo == valorePrecedente) && (valoreSuccessivo >= 10)) {
			matrice[valoreSuccessivo][i] = 238;
			i = i + 1;
		}
	}

}

void Planet::setNavicellaIniziale() {
	for (int i = 1; i < 79; i++)  matrice[1][i] = ' ';  //setta tutta la riga di uscita della navicella con carattere vuoto
	matrice[3][3] = 'Y';                                   //setta la posizione iniziale della navicella quando si entra in un pianeta
}



//stampa del pianeta
void Planet::printPlanet() {  

	system("cls");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << matrice[i][j];
		}
		cout << "\n";
	}

}

bool Planet::toccaSuperfice(int x, int y, char n) {
	bool guardia = true;

	if (matrice[x][y] != ' ') guardia = false;

	return guardia;
}

bool Planet::uscitaPianeta(int x, int y, char n) {
	bool guardia = true;
	if (n == 72 && x == 0) guardia = false;
	return guardia;
}

void Planet::setMatricePlanet(int x, int y, char n) {
	if (n == 75 && y > 0) { 	//left
			matrice[x][y] = 'Y';
			matrice[x][y + 1] = ' ';
	}

	else if (n == 77 && y < 79) { 		//righ
			matrice[x][y] = 'Y';
			matrice[x][y - 1] = ' ';
	}

	else if (n == 72 && x > 0) {		//up
			matrice[x][y] = 'Y';
			matrice[x + 1][y] = ' ';
	}

	else if (n == 80 && x < 20) {		//down
		matrice[x][y] = 'Y';
		matrice[x - 1][y] = ' ';
	}
}

