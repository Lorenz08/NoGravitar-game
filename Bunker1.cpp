#include <iostream>
#include "Bunker1.h"
using namespace std;




Bunker1::Bunker1(int x, int y, int life) {
	xBunker1 = x;
	yBunker1 = y;
	lifeBunker1 = life;
	LPsx = new BulletsList();
	LPdx = new BulletsList();
}


int Bunker1::coordinateBunker1(bool b) {
	if (b) return xBunker1;
	else return yBunker1;
}

void Bunker1::minusLife() {
	lifeBunker1--;
}

int Bunker1::returnLife() {
	return lifeBunker1;
}

void Bunker1::addBulletSBunker1() {
	LPsx->addBullets(xBunker1, yBunker1, false);
	LPdx->addBullets(xBunker1, yBunker1, false);
}

void Bunker1::deleteBulletSBunker1() {
	LPsx->deleteBullets();
	LPdx->deleteBullets();
}

void Bunker1::deleteAllBulletsBunker1() {
	ptr_Bullet tmpSx = LPsx->listaProiettili;
	while (tmpSx != NULL) {
		tmpSx->eliminato = true;
		tmpSx = tmpSx->next;
	}
	ptr_Bullet tmpDx = LPdx->listaProiettili;
	while (tmpDx != NULL) {
		tmpDx->eliminato = true;
		tmpDx = tmpDx->next;
	}
	while (LPsx->listaProiettili != NULL) LPsx->deleteBullets();
	while (LPdx->listaProiettili != NULL) LPdx->deleteBullets();
}
