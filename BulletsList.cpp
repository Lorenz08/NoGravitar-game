#include <iostream>
#include "BulletsList.h"
#include "Spaceship.h"

using namespace std;



BulletsList::BulletsList() {
	listaProiettili = NULL;
}

void BulletsList::addBullets(int x, int y, bool b) {
	if (listaProiettili == NULL) {
		listaProiettili = new Bullet();
		listaProiettili->xBullet = x;
		listaProiettili->yBullet = y;
		listaProiettili->eliminato = b;
		listaProiettili->next = NULL;
	}
	else if (listaProiettili->next == NULL) {
		listaProiettili->next = new Bullet();
		listaProiettili->next->xBullet = x;
		listaProiettili->next->yBullet = y;
		listaProiettili->next->eliminato = b;
		listaProiettili->next->next = NULL;
	}
	else {
		ptr_Bullet tmp, tmpOld;
		tmpOld = listaProiettili;
		tmp = listaProiettili->next;
		while (tmpOld->next->next != NULL) {
			tmp = tmp->next;
			tmpOld = tmpOld->next;
		}
		tmp->next = new Bullet();
		tmp->next->xBullet = x;
		tmp->next->yBullet = y;
		tmp->next->eliminato = b;
		tmp->next->next = NULL;
		tmp = NULL;
		tmpOld = NULL;
		delete tmp;
		delete tmpOld;
	}
}

void BulletsList::deleteBullets() {
	if (listaProiettili != NULL) {
		if (listaProiettili->eliminato == true) {
			if (listaProiettili->next != NULL) {
				ptr_Bullet tmp = listaProiettili;
				listaProiettili = listaProiettili->next;
				delete tmp;
			}
			else {
				ptr_Bullet tmp = listaProiettili;
				listaProiettili = NULL;
				delete tmp;
			}
		}
	}
}

ptr_Bullet BulletsList::retrunList() {
	return listaProiettili;
}


