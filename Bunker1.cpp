#include <iostream>
#include "Bunker1.h"
using namespace std;




Bunker1::Bunker1(int x, int y, int life) {
	xBunker1 = x;
	yBunker1 = y;
	lifeBunker1 = life;
}


int Bunker1::coordinateBunker1(bool b) {
	if (b) return xBunker1;
	else return yBunker1;
}

void Bunker1::minusLife() {
	lifeBunker1--;
}