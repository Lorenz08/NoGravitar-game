#include <iostream>
#include "Bunker2.h"
using namespace std;




Bunker2::Bunker2(int x, int y, int life) {
	xBunker2 = x;
	yBunker2 = y;
	lifeBunker2 = life;
	LPsx = new BulletsList();
	LPdx = new BulletsList(); 
	LPcentrale = new BulletsList();
}


int Bunker2::coordinateBunker2(bool b) {
	if (b) return xBunker2;
	else return yBunker2;
}

void Bunker2::minusLife() {
	lifeBunker2--;
}

int Bunker2::returnLife() {
	return lifeBunker2;
}

void Bunker2::addBulletSBunker2() {
	LPsx->addBullets(xBunker2, yBunker2, false);
	LPdx->addBullets(xBunker2, yBunker2, false);
	LPcentrale->addBullets(xBunker2, yBunker2, false);
}

void Bunker2::deleteBulletSBunker2() {
	LPsx->deleteBullets();
	LPdx->deleteBullets();
	LPcentrale->deleteBullets();
}


void Bunker2::deleteAllBulletsBunker2() {
	ptr_Bullet tmpSx = LPsx->listaProiettili;
	while (tmpSx != NULL) {
		tmpSx->eliminato = true;
		tmpSx = tmpSx->next;
	}
	ptr_Bullet tmpCentrale = LPcentrale->listaProiettili;
	while (tmpCentrale != NULL) {
		tmpCentrale->eliminato = true;
		tmpCentrale = tmpCentrale->next;
	}
	ptr_Bullet tmpDx = LPdx->listaProiettili;
	while (tmpDx != NULL) {
		tmpDx->eliminato = true;
		tmpDx = tmpDx->next;
	}
	while (LPsx->listaProiettili != NULL) LPsx->deleteBullets();
	while (LPcentrale->listaProiettili != NULL) LPcentrale->deleteBullets();
	while (LPdx->listaProiettili != NULL) LPdx->deleteBullets();
}