#include <iostream>
#include "Bunker2.h"
using namespace std;




Bunker2::Bunker2(int x, int y, int life) {
	xBunker2 = x;
	yBunker2 = y;
	lifeBunker2 = life;
	proiettile = NULL;
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

ptr_Bullets Bunker2::returnPointer() {
	return proiettile;
}

void Bunker2::setPointer(ptr_Bullets p) {
	proiettile = p;
}