#include <iostream>
#include <Windows.h>
#include "PlanetSurface.h"
using namespace std;



PlanetSurface::PlanetSurface(Spaceship spaceship, ptr_listaBunker1& head1, ptr_listaBunker2& head2) {
	punt = NULL;

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
			if (i % 77 == 0) head1 = creaBunkerList1(head1, i, valoreSuccessivo - 2);
			if (i % 65 == 0) head2 = creaBunkerList2(head2, i, valoreSuccessivo - 2);
			i = i + 1;
		}
		else if ((valoreSuccessivo == valorePrecedente) && (valoreSuccessivo >= 10)) {
			matrice[i][valoreSuccessivo] = 238;
			if ((i % 25) == 0) matrice[i][valoreSuccessivo - 1] = 'C';
			if ((i % 10) == 0) matrice[i][valoreSuccessivo - 1] = 'c';
			i = i + 1;
		}
	}
	ptr_listaBunker1 tmp1 = head1;
	while (tmp1 != NULL) {
		matrice[tmp1->b1->coordinateBunker1(true)][tmp1->b1->coordinateBunker1(false)] = 'B';
		tmp1 = tmp1->next;
	}

	ptr_listaBunker2 tmp2 = head2;
	while (tmp2 != NULL) {
		matrice[tmp2->b2->coordinateBunker2(true)][tmp2->b2->coordinateBunker2(false)] = 'b';
		tmp2 = tmp2->next;
	}
}


ptr_listaBunker1 PlanetSurface::creaBunkerList1(ptr_listaBunker1 head, int xB, int yB) {
	if (head == NULL) {
		head = new listaBunker1();
		head->b1 = new Bunker1(xB, yB, 3);
		head->next = NULL;
		head->prev = NULL;
	}
	else if (head->next == NULL) {
		head->next = new listaBunker1();
		head->next->b1 = new Bunker1(xB, yB, 3);
		head->next->next = NULL;
		head->next->prev = head;
	}
	else {
		ptr_listaBunker1 tmp, tmpOld;
		tmpOld = head;
		tmp = head->next;
		while (tmpOld->next->next != NULL) {
			tmp = tmp->next;
			tmpOld = tmpOld->next;
		}
		tmp->next = new listaBunker1();
		tmp->next->b1 = new Bunker1(xB, yB, 3);
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
	}
	return head;
}


ptr_listaBunker2 PlanetSurface::creaBunkerList2(ptr_listaBunker2 head, int xB, int yB) {
	if (head == NULL) {
		head = new listaBunker2();
		head->b2 = new Bunker2(xB, yB, 3);
		head->next = NULL;
		head->prev = NULL;
	}
	else if (head->next == NULL) {
		head->next = new listaBunker2();
		head->next->b2 = new Bunker2(xB, yB, 3);
		head->next->next = NULL;
		head->next->prev = head;
	}
	else {
		ptr_listaBunker2 tmp, tmpOld;
		tmpOld = head;
		tmp = head->next;
		while (tmpOld->next->next != NULL) {
			tmp = tmp->next;
			tmpOld = tmpOld->next;
		}
		tmp->next = new listaBunker2();
		tmp->next->b2 = new Bunker2(xB, yB, 3);
		tmp->next->next = NULL;
		tmp->next->prev = tmp;
	}
	return head;
}

void PlanetSurface::spostamentoPlaetSurface(char& moveSpaceshipUniverso) {
	if (GetAsyncKeyState(VK_UP)) moveSpaceshipUniverso = 72;
	else if (GetAsyncKeyState(VK_LEFT)) moveSpaceshipUniverso = 75;
	else if (GetAsyncKeyState(VK_RIGHT)) moveSpaceshipUniverso = 77;
	else if (GetAsyncKeyState(VK_DOWN)) moveSpaceshipUniverso = 80;
	else if (GetAsyncKeyState(0x51)) moveSpaceshipUniverso = 'q';
	else if (GetAsyncKeyState(VK_SHIFT)) moveSpaceshipUniverso = 'p';
	else moveSpaceshipUniverso = 'w';
	
}

char PlanetSurface::interationSpaceshipPlanetSurface(Spaceship & p) {
	char n;
	spostamentoPlaetSurface(n);
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
	else if (n == 'p') {
		addBullets(p.returnParameter(3), p.returnParameter(4) +1);
		refresh();
	}

	return n;
}


void PlanetSurface::setMappPlanetSurface(Spaceship & p, char n, bool& uscitaPianeta) {
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


void PlanetSurface::raggioTraenteUscente(Spaceship & p) {
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

void PlanetSurface::addBullets(int x, int y) {
	if (punt == NULL) {
		punt = new listaBullets;
		punt->xCoordinate = x;
		punt->yCoordinate = y;
		punt->eliminato = false;
		punt->next = NULL;
	}
	else {
		ptr_listaBullets tmp = punt;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new listaBullets;
		tmp->next->eliminato = false;
		tmp = tmp->next;
		tmp->xCoordinate= x;
		tmp->yCoordinate = y;
		tmp->next = NULL;
	}
}

ptr_listaBullets PlanetSurface::deleteBullets(ptr_listaBullets p) {

	/*if (p != NULL) {
		if (p->eliminato == true) {
			ptr_listaBullets tmp = p;
			p = p->next;
			delete tmp;
			return(p);
		}
		else if (p->next != NULL && p->next->eliminato == true) {
			ptr_listaBullets tmp_1 = p;
			ptr_listaBullets tmp_2 = p->next;
			tmp_1->next = tmp_1->next->next;
			delete tmp_2;
			return(p);
		}
		else
			return(p);
	}
	else {
		return(p);
	}*/

	if (p == NULL)
		return NULL;

	else if (p->eliminato == true) {
		ptr_listaBullets tmp = p;
		p = p->next;
		delete tmp;
		return deleteBullets(p);
	}

	else {
		p->next = deleteBullets(p->next);
		return p;
	}
}

void PlanetSurface::refresh() {
	ptr_listaBullets tmp = punt;

	while (tmp != NULL) {
		if (matrice[tmp->xCoordinate][tmp->yCoordinate] == ' ' || matrice[tmp->xCoordinate][tmp->yCoordinate] == 'b' || matrice[tmp->xCoordinate][tmp->yCoordinate] == 'B') {

			matrice[tmp->xCoordinate][tmp->yCoordinate-1] = ' ';

			tmp->xCoordinate = tmp->xCoordinate;
			tmp->yCoordinate = tmp->yCoordinate + 1;

			matrice[tmp->xCoordinate][tmp->yCoordinate-1] = '.';
		}
		else 
			tmp->eliminato = true;

		tmp = tmp->next;
	}

	punt = deleteBullets(punt);

}


