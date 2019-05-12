#include <iostream>
#include "PlanetSurface.h"
using namespace std;



PlanetSurface::PlanetSurface(Spaceship spaceship, ptr_listaBunker &head){
	setMapp();
	setPlanetSurfaceParameters(spaceship.returnParameter(100), spaceship.returnParameter(10));
	matrice[spaceship.returnParameter(3)][spaceship.returnParameter(4)] = 'Y';
	
	//setta la posizione del primo carattere che va a formare la superficie del pianeta (da 10 a 16)
	int valorePrecedente = ((rand() % 7) + 10);

	//valore successivo, serivirà poi per fare il confronto con valorePrcedente per formare una superficie 
	//dove lo scostamento tra un carattere e l'altro è solo di 1
	int valoreSuccessivo = 0;

	//setta il resto della superficie facendo dei confronti per avere uno scostamento (negativo o positivo) massimo di 1
	int i = 1;
	while (i <= 77) {
		valoreSuccessivo = (rand() % 16) + 1;

		if ((valoreSuccessivo == valorePrecedente - 1) && (valoreSuccessivo >= 10)) {
			matrice[i][valoreSuccessivo] = '/';
			valorePrecedente = valoreSuccessivo;
			i = i + 1;
		}
		else if ((valoreSuccessivo == valorePrecedente + 1) && (valoreSuccessivo >= 10)) {
			matrice[i][valoreSuccessivo - 1] = 92;
			valorePrecedente = valoreSuccessivo;
			if (i%37 == 0) head = creaBunkerList(head, i, valoreSuccessivo - 2);
			i = i + 1;
		}
		else if ((valoreSuccessivo == valorePrecedente) && (valoreSuccessivo >= 10)) {
			matrice[i][valoreSuccessivo] = 238;
			if ((i % 25) == 0) matrice[i][valoreSuccessivo - 1] = 'C';
			if ((i % 10) == 0) matrice[i][valoreSuccessivo - 1] = 'c';
			i = i + 1;
		}
	}
	ptr_listaBunker tmp = head;
	while (tmp != NULL) {
		matrice[tmp->b1->coordinateBunker(true)][tmp->b1->coordinateBunker(false)] = 'P';
		tmp = tmp->next;
	}
}


ptr_listaBunker PlanetSurface::creaBunkerList(ptr_listaBunker head, int xB, int yB) {
	if (head == NULL) {
		head = new listaBunker();
		head->b1 = new Bunker(xB, yB, 3);
		head->next = NULL;
		head->prev = NULL;
	}
	else if (head->next == NULL) {
		head->next = new listaBunker();
		head->next->b1 = new Bunker(xB, yB, 3);
		head->next->next = NULL;
		head->next->prev = head;
	}
	else {
		ptr_listaBunker tmp, tmpOld;
		tmpOld = head;
		tmp = head->next;
		while (tmpOld->next->next != NULL) {
			tmp = tmp->next;
			tmpOld = tmpOld->next;
		}
		tmp->next = new listaBunker();
		tmp->next->b1 = new Bunker(xB, yB, 3);
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
	}
	return head;
}


void PlanetSurface::interationSpaceship2(Spaceship &p, char n) {
	if ((n == 75) && (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] != '|')) {
		if (matrice[p.returnParameter(3) - 1][p.returnParameter(4)] == ' ') p.moveSpaceshipPlanet(n);
		else {
			if ((matrice[p.returnParameter(3) - 1][p.returnParameter(4)] != 'C') || (matrice[p.returnParameter(3) - 1][p.returnParameter(4)] != 'c')) p.lifeMinus();
		}
	}
	else if ((n == 77) && (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] != '|')) {
		if (matrice[p.returnParameter(3) + 1][p.returnParameter(4)] == ' ') p.moveSpaceshipPlanet(n);
		else {
			if ((matrice[p.returnParameter(3) + 1][p.returnParameter(4)] != 'C') || (matrice[p.returnParameter(3) + 1][p.returnParameter(4)] != 'c')) p.lifeMinus();
		}
	}
	else if ((n == 72) && (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] != '|')) {
		p.moveSpaceshipPlanet(n);
	}
	else if ((n == 80) && (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] != '|')) {
		if (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] == ' ')p.moveSpaceshipPlanet(n);
		else {
			if ((matrice[p.returnParameter(3)][p.returnParameter(4) + 1] != 'C') || (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] != 'c')) p.lifeMinus();
		}
	}
	else if (n == 'q') raggioTraenteUscente(p);
	else if (n == 'w') raggioTraenteEntrante(p);
}


void PlanetSurface::setMappPlanetSurface(Spaceship &p, char n, bool &uscitaPianeta) {
	setPlanetSurfaceParameters(p.returnParameter(100), p.returnParameter(10));
	for (int i = 1; i < 78; i++) matrice[i][1] = ' ';
	matrice[p.returnParameter(3)][p.returnParameter(4)] = 'Y';
	for (int i = 1; i < 78; i++) matrice[i][0] = 205;
	if (matrice[p.returnParameter(3) + 1][p.returnParameter(4)] == 'Y') matrice[p.returnParameter(3) + 1][p.returnParameter(4)] = ' ';
	if (matrice[p.returnParameter(3) - 1][p.returnParameter(4)] == 'Y') matrice[p.returnParameter(3) - 1][p.returnParameter(4)] = ' ';
	if (matrice[p.returnParameter(3)][p.returnParameter(4) - 1] == 'Y') matrice[p.returnParameter(3)][p.returnParameter(4) - 1] = ' ';
	if (n == 72) {
		if (p.returnParameter(4) >= 1) {
			if (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] == 'Y') matrice[p.returnParameter(3)][p.returnParameter(4) + 1] = ' ';
		}
		else {
			uscitaPianeta = false;
			p.setInitialPosition();
			matrice[p.returnParameter(3)][p.returnParameter(4)] = 'Y';
		}
	}
}


void PlanetSurface::raggioTraenteUscente(Spaceship& p) {
	int x = p.returnParameter(3);
	int y = p.returnParameter(4);
	while ((matrice[x][y + 1] == ' ') || (matrice[x][y + 1] == 'c') || (matrice[x][y + 1] == 'C')) {
		if (matrice[x][y + 1] == 'C') {
			matrice[x][y + 1] = ' ';
			p.fuelPlus(0);
		}
		else if (matrice[x][y + 1] == 'c') {
			matrice[x][y + 1] = ' ';
			p.fuelPlus(1);
		}
		else matrice[x][y + 1] = '|';
		y++;
	}
}


void PlanetSurface::raggioTraenteEntrante(Spaceship p) {
	int x = p.returnParameter(3);
	int y = p.returnParameter(4);
	while (matrice[x][y + 1] == '|') {
		matrice[x][y + 1] = ' ';
		y++;
	}
}