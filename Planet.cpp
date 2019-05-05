#include <iostream>
#include <conio.h>
#include <ctime>
#include "windows.h"
#include "Spaceship.h"
#include "Planet.h"
#include "Infinito.h"
#include "Mapp.h"

using namespace std;


Planet::Planet() {

	Mapp::setMapp();

	//setta la posizione del primo '*' che va a formare la superficie del pianeta (da 10 a 16)
	int valorePrecedente = ((rand() % 7) + 10); 

	//valore successivo, serivirà poi per fare il confronto con valorePrcedente per formare una superficie 
	//dove lo scostamento tra un '*' e l'altro è solo di 1
	int valoreSuccessivo = 0; 
	

	//imposta il limite superiore del primo '*' (minimo 10, massimo 16)
	//matrice[valorePrecedente][1] = 238;

	//setta il resto della superficie facendo dei confronti per avere uno scostamento (negativo o positivo) massimo di 1
	int i = 1;
	while (i <= 77) {
		valoreSuccessivo = (rand() % 16) + 1;

		if ((valoreSuccessivo == valorePrecedente - 1) && (valoreSuccessivo >= 10)) {
			matrice[valoreSuccessivo][i] = '/';
			valorePrecedente = valoreSuccessivo;
			i = i + 1;
		}
		else if ((valoreSuccessivo == valorePrecedente + 1) && (valoreSuccessivo >= 10)) {
			matrice[valoreSuccessivo-1][i] = 92;
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
	for (int i = 1; i < 78; i++)  matrice[1][i] = ' ';     //setta tutta la riga di uscita della navicella con carattere vuoto
	matrice[3][3] = 203;                                   //setta la posizione iniziale della navicella quando si entra in un pianeta
}


bool Planet::toccaCornice(int x, int y) {
	if (matrice[x][y] != ' ') return false;
	else return true;
}


bool Planet::toccaSuperficie(int x, int y, char m) {
	if ((matrice[x][y-1] != ' ') && (m == 75) && (y >0)) return true;  //sinistra
	if ((matrice[x][y+1] != ' ') && (m == 77) && (y < 78)) return true;  //destra
	if ((matrice[x][y] != ' ') && (m == 80)) return true;  //giu
	else return false;
}


bool Planet::uscitaPianeta(int x, int y, char n) {
	if (n == 72 && x == 0) return false;
	else return true;
}


void Planet::newSpaceshipPositionPlanet(int x, int y, char n) {
	if (n == 75 && y > 0) { 	//left
			matrice[x][y] = 203;
			matrice[x][y + 1] = ' ';
	}

	else if (n == 77 && y < 79) { 		//righ
			matrice[x][y] = 203;
			matrice[x][y - 1] = ' ';
	}

	else if (n == 72 && x > 0) {		//up
			matrice[x][y] = 203;
			matrice[x + 1][y] = ' ';
	}

	else if (n == 80 && x < 20) {		//down
		matrice[x][y] = 203;
		matrice[x - 1][y] = ' ';
	}
}


bool Planet::raggioTraenteUscente(int x, int y, int n) {
	bool guardia = true;
	if (matrice[x + n][y] == ' ') matrice[x + n][y] = 176;
	else guardia = false;
	return guardia;
}


void Planet::raggioTraenteEntrante(int x, int y, int n) {
	while (n>1) {
		if (matrice[x + n][y] == '/') matrice[x + (n - 1)][y] = ' ';
		else if (matrice[x + n][y] == 92) matrice[x + (n - 1)][y] = ' ';
		else if (matrice[x + n][y] == 238) matrice[x + (n - 2)][y] = ' ';
		else matrice[x + (n - 1)][y] = ' ';
		n--;
	}
}
