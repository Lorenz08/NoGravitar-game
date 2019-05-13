#include <iostream>
#include "Bunker2.h"
using namespace std;




Bunker2::Bunker2(int x, int y, int life) {
	xBunker2 = x;
	yBunker2 = y;
	lifeBunker2 = life;
}


int Bunker2::coordinateBunker2(bool b) {
	if (b) return xBunker2;
	else return yBunker2;
}
