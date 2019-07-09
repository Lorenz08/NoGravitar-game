#include <iostream>
#include <Windows.h>
#include "PlanetSurface.h"
using namespace std;


//metodo che costruisce l'oggetto "PlanetSurface"
//vengono passati come parametri la "Spaceship" e i puntatori delle due liste di Bunker presenti nella struttura "Planet"
PlanetSurface::PlanetSurface(Spaceship spaceship, ptr_listaBunker1& head1, ptr_listaBunker2& head2) {
	//setta la schermata inziale 
	setMapp();
	setPlanetSurfaceParameters(spaceship.returnParameter(100), spaceship.returnParameter(10), spaceship.returnParameter(200));
	matrice[spaceship.returnParameter(3)][spaceship.returnParameter(4)] = 'Y';

	//setta la posizione del primo carattere che va a formare la superficie del pianeta (da 10 a 16)
	int valorePrecedente = ((rand() % 7) + 10);

	//valore successivo, serivirà poi per fare il confronto con valorePrcedente per formare una superficie 
	//dove lo scostamento tra un carattere e l'altro è solo di 1
	int valoreSuccessivo = 0;

	//setta il resto della superficie facendo dei confronti per avere uno scostamento (negativo o positivo) al massimo di 1
	int lunghezzaSuperficie = 1;   //serve per impostare la lunghezza della superficie del pianeta
	int numeroBunker1 = 0;         //serve per avere un limite di Buneker1 nel pianeta
	int numeroBunker2 = 0;         //serve per avere un limite di Buneker2 nel pianeta
	int tmp = 0;                   //serve per non piazzare due bunker troppo vicini 

	while (lunghezzaSuperficie <= 77) {
		valoreSuccessivo = (rand() % 16) + 1;
		int riempimento = 0;
		//se il valore di "valoreSuccessivo" è maggiore di 1 rispetto a "valorePrecedente", allora la superficie salirà di carattere
		if ((valoreSuccessivo == valorePrecedente - 1) && (valoreSuccessivo >= 10)) {
			matrice[lunghezzaSuperficie][valoreSuccessivo] = '/';
			riempimento = valoreSuccessivo + 1;
			
			while (riempimento < 20) {    //serve per inserire i puntini al di sotto della superficie (per poi colorarla)
				matrice[lunghezzaSuperficie][riempimento] = 34;
				riempimento++;
			}

			valorePrecedente = valoreSuccessivo; //si fa il passaggio del valore per il prossimo confronto 

			if ((lunghezzaSuperficie >= tmp + 10) && (numeroBunker1 <= 1) && (lunghezzaSuperficie % ((rand() % 15) + 1) == 0)) {
				head1 = creaBunkerList1(head1, lunghezzaSuperficie, valoreSuccessivo - 1);
				tmp = lunghezzaSuperficie;
				numeroBunker1++;
			}
			if ((lunghezzaSuperficie >= tmp + 10) && (numeroBunker2 < 1) && (lunghezzaSuperficie % 5 == 0) && (matrice[lunghezzaSuperficie][valoreSuccessivo - 1] == ' ')) {
				head2 = creaBunkerList2(head2, lunghezzaSuperficie, valoreSuccessivo - 1);
				tmp = lunghezzaSuperficie;
				numeroBunker2++;
			}
			lunghezzaSuperficie++;
		}
		else if ((valoreSuccessivo == valorePrecedente + 1) && (valoreSuccessivo >= 10)) {
			matrice[lunghezzaSuperficie][valoreSuccessivo - 1] = 92;
			riempimento = valoreSuccessivo;
			while (riempimento < 20) {
				matrice[lunghezzaSuperficie][riempimento] = 34;
				riempimento++;
			}
			valorePrecedente = valoreSuccessivo;
			if ((lunghezzaSuperficie >= tmp + 10) && (numeroBunker1 <= 2) && (lunghezzaSuperficie % ((rand() % 3) + 4) == 0)) {
				head1 = creaBunkerList1(head1, lunghezzaSuperficie, valoreSuccessivo - 2);
				tmp = lunghezzaSuperficie;
				numeroBunker1++;
			}
			if ((lunghezzaSuperficie >= tmp + 10) && (numeroBunker2 < 1) && (lunghezzaSuperficie % 5 == 0) && (matrice[lunghezzaSuperficie][valoreSuccessivo - 1] == ' ')) {
				head2 = creaBunkerList2(head2, lunghezzaSuperficie, valoreSuccessivo - 2);
				tmp = lunghezzaSuperficie;
				numeroBunker2++;
			}
			lunghezzaSuperficie++;
		}
		else if ((valoreSuccessivo == valorePrecedente) && (valoreSuccessivo >= 10)) {
			matrice[lunghezzaSuperficie][valoreSuccessivo] = 34;
			riempimento = valoreSuccessivo + 1;
			while (riempimento < 20) {
				matrice[lunghezzaSuperficie][riempimento] = 34;
				riempimento++;
			}
			if ((lunghezzaSuperficie % 25) == 0) matrice[lunghezzaSuperficie][valoreSuccessivo - 1] = 'C';
			if ((lunghezzaSuperficie % 10) == 0) matrice[lunghezzaSuperficie][valoreSuccessivo - 1] = 'c';
			lunghezzaSuperficie++;
		}
	}


	LBunker1 = head1;
	LBunker2 = head2;

	ptr_listaBunker1 tmp1 = head1;
	while (tmp1 != NULL) {
		matrice[tmp1->b1->coordinateBunker1(true)][tmp1->b1->coordinateBunker1(false)] = 'b';
		tmp1 = tmp1->next;
	}

	ptr_listaBunker2 tmp2 = head2;
	while (tmp2 != NULL) {
		matrice[tmp2->b2->coordinateBunker2(true)][tmp2->b2->coordinateBunker2(false)] = 'B';
		tmp2 = tmp2->next;
	}

}


ptr_listaBunker1 PlanetSurface::creaBunkerList1(ptr_listaBunker1 head, int xB, int yB) {
	if (head == NULL) {
		head = new listaBunker1();
		head->b1 = new Bunker1(xB, yB, 3);
		head->next = NULL;
	}
	else if (head->next == NULL) {
		head->next = new listaBunker1();
		head->next->b1 = new Bunker1(xB, yB, 3);
		head->next->next = NULL;
	}
	else {
		ptr_listaBunker1 tmpOld, tmpNew;
		tmpOld = head;
		tmpNew = head->next;
		while (tmpOld->next->next != NULL) {
			tmpOld = tmpNew;
			tmpNew = tmpNew->next;
		}
		ptr_listaBunker1 tmp;
		tmp = new listaBunker1();
		tmp->b1 = new Bunker1(xB, yB, 3);
		tmp->next = NULL;
		tmpNew->next = tmp;
		tmp = NULL;
		tmpOld = NULL;
		tmpNew = NULL;
		delete tmp;
		delete tmpOld;
		delete tmpNew;
	}
	return head;
}


ptr_listaBunker2 PlanetSurface::creaBunkerList2(ptr_listaBunker2 head, int xB, int yB) {
	if (head == NULL) {
		head = new listaBunker2();
		head->b2 = new Bunker2(xB, yB, 3);
		head->next = NULL;
	}
	else if (head->next == NULL) {
		head->next = new listaBunker2();
		head->next->b2 = new Bunker2(xB, yB, 3);
		head->next->next = NULL;
	}
	else {
		ptr_listaBunker2 tmpOld, tmpNew;
		tmpOld = head;
		tmpNew = head->next;
		while (tmpOld->next->next != NULL) {
			tmpOld = tmpNew;
			tmpNew = tmpNew->next;
		}
		ptr_listaBunker2 tmp;
		tmp = new listaBunker2();
		tmp->b2 = new Bunker2(xB, yB, 3);
		tmp->next = NULL;
		tmpNew->next = tmp;
		tmp = NULL;
		tmpOld = NULL;
		tmpNew = NULL;
		delete tmp;
		delete tmpOld;
		delete tmpNew;
	}
	return head;
}


void PlanetSurface::spostamentoPlaetSurface(char& moveSpaceshipUniverso) {
	if (GetAsyncKeyState(VK_UP)) moveSpaceshipUniverso = 72;
	else if (GetAsyncKeyState(VK_LEFT)) moveSpaceshipUniverso = 75;
	else if (GetAsyncKeyState(VK_RIGHT)) moveSpaceshipUniverso = 77;
	else if (GetAsyncKeyState(VK_DOWN)) moveSpaceshipUniverso = 80;
	else if (GetAsyncKeyState(0x51)) moveSpaceshipUniverso = 'q';
	else if (GetAsyncKeyState(' ')) moveSpaceshipUniverso = 'z';
	else moveSpaceshipUniverso = 'w';
}


char PlanetSurface::interationSpaceshipPlanetSurface(Spaceship & p, bool& pianetaDistrutto) {
	char n;
	spostamentoPlaetSurface(n);
	if ((n == 75) && (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] != '|')) {
		if (matrice[p.returnParameter(3) - 1][p.returnParameter(4)] == ' ') p.moveSpaceshipPlanet(n);
		else {
			if (((matrice[p.returnParameter(3) - 1][p.returnParameter(4)] != 'C') || (matrice[p.returnParameter(3) - 1][p.returnParameter(4)] != 'c')) && (p.returnParameter(3) > 1)) p.lifeMinus();
		}
	}
	else if ((n == 77) && (matrice[p.returnParameter(3)][p.returnParameter(4) + 1] != '|')) {
		if (matrice[p.returnParameter(3) + 1][p.returnParameter(4)] == ' ') p.moveSpaceshipPlanet(n);
		else {
			if (((matrice[p.returnParameter(3) + 1][p.returnParameter(4)] != 'C') || (matrice[p.returnParameter(3) + 1][p.returnParameter(4)] != 'c')) && (p.returnParameter(3) < 77)) p.lifeMinus();
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
	else if (n == 'z') {
		p.addBulletSPaceship();
	}
	refreshSpaceship(p, LBunker1, LBunker2);
	return n;
}


void PlanetSurface::setMappPlanetSurface(Spaceship & p, char n, bool& uscitaPianeta) {
	setPlanetSurfaceParameters(p.returnParameter(100), p.returnParameter(10), p.returnParameter(200));
	for (int i = 1; i < 78; i++) {
		if (matrice[i][1] == 'Y') matrice[i][1] = ' ';
	}
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
	while ((matrice[x][y + 1] == ' ') || (matrice[x][y + 1] == 'c') || (matrice[x][y + 1] == 'C') || (matrice[x][y + 1] == '.')) {
		if (matrice[x][y + 1] == 'C') {
			matrice[x][y + 1] = ' ';
			p.fuelPlus(0);
		}
		else if (matrice[x][y + 1] == 'c') {
			matrice[x][y + 1] = ' ';
			p.fuelPlus(1);
		}
		else {
			matrice[x][y + 1] = '|';
			if (matrice[x - 1][y + 1] == '.') matrice[x - 1][y + 1] = ' ';
			if (matrice[x + 1][y + 1] == '.') matrice[x + 1][y + 1] = ' ';
		}
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


void PlanetSurface::sparaBunker(Spaceship & p, int& i) {
	refreshBunker1(p, LBunker1, i);
	refreshBunker2(p, LBunker2, i);
	i++;
	if (i == 12) i = 0;
}


void PlanetSurface::refreshBunker1(Spaceship & p, ptr_listaBunker1 & head1, int i) {
	ptr_listaBunker1 tmp1 = head1;
	if ((i == 0) || (i == 5)) {
		while (tmp1 != NULL) {
			if (matrice[tmp1->b1->coordinateBunker1(true)][tmp1->b1->coordinateBunker1(false)] == 'b') tmp1->b1->addBulletSBunker1();
			tmp1 = tmp1->next;
		}
	}
	tmp1 = head1;
	while (tmp1 != NULL) {
		ptr_Bullet tmpSx = tmp1->b1->returnLP(1)->retrunList();
		while (tmpSx != NULL) {
			tmpSx->xBullet--;
			tmpSx->yBullet--;
			if ((matrice[tmpSx->xBullet][tmpSx->yBullet] == ' ') || (matrice[tmpSx->xBullet][tmpSx->yBullet] == '.')) {
				if (matrice[tmpSx->xBullet - 1][tmpSx->yBullet - 1] != '|') matrice[tmpSx->xBullet][tmpSx->yBullet] = '.';
				if (matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] != '|') {
					if (matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] != 'b') matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] = ' ';
				}
			}
			if (tmpSx->yBullet <= 0) {
				matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] = ' ';
				tmpSx->eliminato = true;
			}
			if (tmpSx->xBullet <= 0) {
				matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] = ' ';
				tmpSx->eliminato = true;
			}
			if (matrice[tmpSx->xBullet][tmpSx->yBullet] == 'Y') {
				p.lifeMinus();
				if (matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] != 'b') matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] = ' ';
			}
			if ((tmpSx->xBullet == 0) && (tmpSx->yBullet == 0)) {
				tmpSx->eliminato = true;
				matrice[0][0] = 201;
			}
			tmpSx = tmpSx->next;
		}
		ptr_Bullet tmpDx = tmp1->b1->returnLP(2)->retrunList();
		while (tmpDx != NULL) {
			tmpDx->xBullet++;
			tmpDx->yBullet--;
			if ((matrice[tmpDx->xBullet][tmpDx->yBullet] == ' ') || (matrice[tmpDx->xBullet][tmpDx->yBullet] == '.')) {
				if (matrice[tmpDx->xBullet + 1][tmpDx->yBullet - 1] != '|') matrice[tmpDx->xBullet][tmpDx->yBullet] = '.';
				if (matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] != '|') {
					if (matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] != 'b') matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] = ' ';
				}
			}
			if (tmpDx->yBullet <= 0) {
				tmpDx->eliminato = true;
				matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] = ' ';
			}
			if (tmpDx->xBullet >= 78) {
				matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] = ' ';
				tmpDx->eliminato = true;
			}
			if (matrice[tmpDx->xBullet][tmpDx->yBullet] == 'Y') {
				p.lifeMinus();
				if (matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] != 'b') matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] = ' ';
			}
			if ((tmpDx->xBullet == 78) && (tmpDx->yBullet == 0)) {
				tmpDx->eliminato = true;
				matrice[78][0] = 203;
			}
			tmpDx = tmpDx->next;
		}
		tmp1 = tmp1->next;
	}
	tmp1 = head1;
	while (tmp1 != NULL) {
		tmp1->b1->deleteBulletSBunker1();
		tmp1 = tmp1->next;
	}
}


void PlanetSurface::refreshBunker2(Spaceship & p, ptr_listaBunker2 & head2, int i) {
	ptr_listaBunker2 tmp2 = head2;
	if (i == 7) {
		while (tmp2 != NULL) {
			if (matrice[tmp2->b2->coordinateBunker2(true)][tmp2->b2->coordinateBunker2(false)] == 'B')tmp2->b2->addBulletSBunker2();
			tmp2 = tmp2->next;
		}
	}
	tmp2 = head2;
	while (tmp2 != NULL) {
		ptr_Bullet tmpSx = tmp2->b2->returnLP(1)->retrunList();
		while (tmpSx != NULL) {
			tmpSx->xBullet--;
			tmpSx->yBullet--;
			if ((matrice[tmpSx->xBullet][tmpSx->yBullet] == ' ') || (matrice[tmpSx->xBullet][tmpSx->yBullet] == '.')) {
				if (matrice[tmpSx->xBullet - 1][tmpSx->yBullet - 1] != '|') matrice[tmpSx->xBullet][tmpSx->yBullet] = '.';
				if (matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] != '|') {
					if (matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] != 'B') matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] = ' ';
				}
			}
			if (tmpSx->yBullet <= 0) {
				matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] = ' ';
				tmpSx->eliminato = true;
			}
			if (tmpSx->xBullet <= 0) {
				matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] = ' ';
				tmpSx->eliminato = true;
			}
			if (matrice[tmpSx->xBullet][tmpSx->yBullet] == 'Y') {
				p.lifeMinus();
				if (matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] != 'B') matrice[tmpSx->xBullet + 1][tmpSx->yBullet + 1] = ' ';
			}
			if ((tmpSx->xBullet == 0) && (tmpSx->yBullet == 0)) {
				tmpSx->eliminato = true;
				matrice[0][0] = 201;
			}
			tmpSx = tmpSx->next;
		}
		ptr_Bullet tmpCentrale = tmp2->b2->returnLP(3)->retrunList();
		while (tmpCentrale != NULL) {
			tmpCentrale->yBullet--;
			if ((matrice[tmpCentrale->xBullet][tmpCentrale->yBullet] == ' ') || (matrice[tmpCentrale->xBullet][tmpCentrale->yBullet] == '.')) {
				matrice[tmpCentrale->xBullet][tmpCentrale->yBullet] = '.';
				if (matrice[tmpCentrale->xBullet][tmpCentrale->yBullet + 1] != 'B') matrice[tmpCentrale->xBullet][tmpCentrale->yBullet + 1] = ' ';
			}
			if (tmpCentrale->yBullet <= 0) {
				tmpCentrale->eliminato = true;
				if (matrice[tmpCentrale->xBullet][tmpCentrale->yBullet + 1] != 'B') matrice[tmpCentrale->xBullet][tmpCentrale->yBullet + 1] = ' ';
			}
			else if (matrice[tmpCentrale->xBullet][tmpCentrale->yBullet] == 'Y') {
				p.lifeMinus();
				if (matrice[tmpCentrale->xBullet][tmpCentrale->yBullet] == 'Y') 
					if ((matrice[tmpCentrale->xBullet][tmpCentrale->yBullet + 1] != '|') && (matrice[tmpCentrale->xBullet][tmpCentrale->yBullet + 1] != 'B')) matrice[tmpCentrale->xBullet][tmpCentrale->yBullet + 1] = ' ';
			}
			tmpCentrale = tmpCentrale->next;
		}
		ptr_Bullet tmpDx = tmp2->b2->returnLP(2)->retrunList();
		while (tmpDx != NULL) {
			tmpDx->xBullet++;
			tmpDx->yBullet--;
			if ((matrice[tmpDx->xBullet][tmpDx->yBullet] == ' ') || (matrice[tmpDx->xBullet][tmpDx->yBullet] == '.')) {
				if (matrice[tmpDx->xBullet + 1][tmpDx->yBullet - 1] != '|') matrice[tmpDx->xBullet][tmpDx->yBullet] = '.';
				if (matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] != '|') {
					if (matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] != 'B') matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] = ' ';
				}
			}
			if (tmpDx->yBullet <= 0) {
				tmpDx->eliminato = true;
				matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] = ' ';
			}
			if (tmpDx->xBullet >= 78) {
				matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] = ' ';
				tmpDx->eliminato = true;
			}
			if (matrice[tmpDx->xBullet][tmpDx->yBullet] == 'Y') {
				p.lifeMinus();
				if (matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] != 'B') matrice[tmpDx->xBullet - 1][tmpDx->yBullet + 1] = ' ';
			}
			if ((tmpDx->xBullet == 78) && (tmpDx->yBullet == 0)) {
				tmpDx->eliminato = true;
				matrice[78][0] = 203;
			}
			tmpDx = tmpDx->next;
		}
		tmp2 = tmp2->next;
	}
	tmp2 = head2;
	while (tmp2 != NULL) {
		tmp2->b2->deleteBulletSBunker2();
		tmp2 = tmp2->next;
	}
}



void PlanetSurface::refreshSpaceship(Spaceship& p, ptr_listaBunker1& head1, ptr_listaBunker2 & head2) {
	ptr_Bullet tmp = p.returnLP()->retrunList();
	int xx = 0;
	int yy = 0;

	while (tmp != NULL) {
		matrice[tmp->xBullet][tmp->yBullet] = ' ';
		tmp->yBullet++;
		if ((matrice[tmp->xBullet][tmp->yBullet] == ' ') || (matrice[tmp->xBullet][tmp->yBullet] == '.')) {
			matrice[tmp->xBullet][tmp->yBullet] = '.';
		}
		else if (matrice[tmp->xBullet][tmp->yBullet] == 'b') {
			ptr_listaBunker1 tmp1 = head1;
			while ((tmp1->b1->coordinateBunker1(true) != tmp->xBullet) && (tmp1->b1->coordinateBunker1(false) != tmp->yBullet)) tmp1 = tmp1->next;
			tmp->eliminato = true;
			tmp1->b1->minusLife();
			xx = tmp->xBullet;
			yy = tmp->yBullet;

			if (tmp1->b1->returnLife() <= 0)
				p.setScore(1);
		}
		else if (matrice[tmp->xBullet][tmp->yBullet] == 'B') {
			ptr_listaBunker2 tmp2 = head2;
			while ((tmp2->b2->coordinateBunker2(true) != tmp->xBullet) && (tmp2->b2->coordinateBunker2(false) != tmp->yBullet)) tmp2 = tmp2->next;
			tmp->eliminato = true;
			tmp2->b2->minusLife();
			xx = tmp->xBullet;
			yy = tmp->yBullet;

			if (tmp2->b2->returnLife() <= 0)
				p.setScore(2);
		}
		else tmp->eliminato = true;
		tmp = tmp->next;
	}
	p.deleteBulletSPaceship();
	head1 = modificaLista1(head1, xx, yy);
	head2 = modificaLista2(head2, xx, yy);
	if (assenzaBunker()) {
		head1 = NULL;
		head2 = NULL;
	}
}


bool PlanetSurface::assenzaBunker() {
	bool guardia = true;
	for (int y = 0; y <= yMatrice; y++) {
		for (int x = 0; x <= 79; x++) {
			if ((matrice[x][y] == 'b') || (matrice[x][y] == 'B')) guardia = false;
		}
	}
	return guardia;
}

ptr_listaBunker1 PlanetSurface::ritornoBunkerList1() {
	return LBunker1;
}

ptr_listaBunker2 PlanetSurface::ritornoBunkerList2() {
	return LBunker2;
}

void PlanetSurface::eliminareSpariBunker1Distrutto(ptr_listaBunker1 & head) {
	ptr_Bullet tmpSx = head->b1->returnLP(1)->retrunList();
	ptr_Bullet tmpDx = head->b1->returnLP(2)->retrunList();
	while (tmpSx != NULL) {
		matrice[tmpSx->xBullet][tmpSx->yBullet] = ' ';
		tmpSx->eliminato = true;
		tmpSx = tmpSx->next;
	}
	while (tmpDx != NULL) {
		matrice[tmpDx->xBullet][tmpDx->yBullet] = ' ';
		tmpDx->eliminato = true;
		tmpDx = tmpDx->next;
	}
	while (head->b1->returnLP(1)->retrunList() != NULL) head->b1->returnLP(1)->deleteBullets();
	while (head->b1->returnLP(2)->retrunList() != NULL) head->b1->returnLP(2)->deleteBullets();
}


void PlanetSurface::eliminareSpariBunker2Distrutto(ptr_listaBunker2 & head) {
	ptr_Bullet tmpSx = head->b2->returnLP(1)->retrunList();
	ptr_Bullet tmpDx = head->b2->returnLP(2)->retrunList();
	ptr_Bullet tmpCentrale = head->b2->returnLP(3)->retrunList();
	while (tmpSx != NULL) {
		matrice[tmpSx->xBullet][tmpSx->yBullet] = ' ';
		tmpSx = tmpSx->next;
	}
	while (tmpCentrale != NULL) {
		matrice[tmpCentrale->xBullet][tmpCentrale->yBullet] = ' ';
		tmpCentrale = tmpCentrale->next;
	}
	while (tmpDx != NULL) {
		matrice[tmpDx->xBullet][tmpDx->yBullet] = ' ';
		tmpDx = tmpDx->next;
	}
	ptr_listaBunker2 tmp2 = head;
	while (tmp2 != NULL) {
		tmp2->b2->deleteAllBulletsBunker2();
		tmp2 = tmp2->next;
	}
}


/*ptr_listaBunker1 PlanetSurface::modificaLista1(ptr_listaBunker1& head, int x, int y) {
	if (head == NULL) return NULL;
	else if (head->next == NULL) {
		if (head->b1->returnLife() < 1) {
			ptr_listaBunker1 tmp = head;
			eliminareSpariBunker1Distrutto(head);
			matrice[x][y] = ' ';
			delete tmp;
			return NULL;
		}
		else return head;
	}
	else if (head->next != NULL) {
		ptr_listaBunker1 tmpOld, tmp1, tmp2;
		tmpOld = head;
		tmp1 = head;
		tmp2 = head->next;
		while (tmp2 != NULL) {
			if (tmp2->b1->returnLife() < 1) {
				ptr_listaBunker1 tmp = tmp2;
				tmp2 = tmp2->next;
				tmp1->next = tmp2;
				eliminareSpariBunker1Distrutto(tmp);
				matrice[x][y] = ' ';
				delete tmp;
			}
			else {
				tmp1 = tmp2;
				tmp2 = tmp2->next;
			}
		}
		if (tmpOld->b1->returnLife() < 1) {
			ptr_listaBunker1 tmp = tmpOld;
			if (tmpOld->next == NULL) {
				tmpOld = NULL;
				matrice[x][y] = ' ';
				eliminareSpariBunker1Distrutto(tmp);
				delete tmp;
			}
			else {
				tmpOld = tmpOld->next;
				matrice[x][y] = ' ';
				eliminareSpariBunker1Distrutto(tmp);
				delete tmp;
			}
		}
		return tmpOld;
	}
}*/

ptr_listaBunker1 PlanetSurface::modificaLista1(ptr_listaBunker1& head, int x, int y) {
	if (head == NULL) return NULL;
	else if (head->b1->returnLife() < 1) {
		eliminareSpariBunker1Distrutto(head);
		matrice[x][y] = ' ';
		ptr_listaBunker1 tmp = head->next;
		delete head;
		return modificaLista1(tmp, x, y);
	}
	else {
		head->next = modificaLista1(head->next, x, y);
		return head;
	}
}


ptr_listaBunker2 PlanetSurface::modificaLista2(ptr_listaBunker2 head, int x, int y) {
	if (head == NULL) return NULL;
	else if (head->next == NULL) {
		if (head->b2->returnLife() < 1) {
			ptr_listaBunker2 tmp = head;
			eliminareSpariBunker2Distrutto(head);
			matrice[x][y] = ' ';
			delete tmp;
			return NULL;
		}
		else return head;
	}
	else if (head->next != NULL) {
		ptr_listaBunker2 tmpOld, tmp1, tmp2;
		tmpOld = head;
		tmp1 = head;
		tmp2 = head->next;
		while (tmp2 != NULL) {
			if (tmp2->b2->returnLife() < 1) {
				ptr_listaBunker2 tmp = tmp2;
				tmp2 = tmp2->next;
				tmp1->next = tmp2;
				eliminareSpariBunker2Distrutto(tmp);
				matrice[x][y] = ' ';
				delete tmp;
			}
			else {
				tmp1 = tmp2;
				tmp2 = tmp2->next;
			}
		}
		if (tmpOld->b2->returnLife() < 1) {
			ptr_listaBunker2 tmp = tmpOld;
			if (tmpOld->next == NULL) {
				tmpOld = NULL;
				eliminareSpariBunker2Distrutto(tmp);
				matrice[x][y] = ' ';
				delete tmp;
			}
			else {
				tmpOld = tmpOld->next;
				eliminareSpariBunker2Distrutto(tmp);
				matrice[x][y] = ' ';
				delete tmp;
			}
		}
		return tmpOld;
	}
}


void PlanetSurface::azzerareListeBullets(Spaceship & p, bool& b) {
	if (b) {
		for (int y = 0; y <= yMatrice; y++) {
			for (int x = 0; x <= xMatrice; x++) {
				if (matrice[x][y] == '.') matrice[x][y] = ' ';
			}
		}
		p.deleteAllBulletsSpaceship();
		ptr_listaBunker1 tmp1 = LBunker1;
		while (tmp1 != NULL) {
			tmp1->b1->deleteAllBulletsBunker1();
			tmp1 = tmp1->next;
		}
		ptr_listaBunker2 tmp2 = LBunker2;
		while (tmp2 != NULL) {
			tmp2->b2->deleteAllBulletsBunker2();
			tmp2 = tmp2->next;
		}
	}
	b = false;
}