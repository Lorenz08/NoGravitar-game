#include <iostream>
#include "Bunker.h"
using namespace std;




Bunker::Bunker(int x, int y, int life) {
	xBunker = x;
	yBunker = y;
	lifeBunker = life;
}


int Bunker::coordinateBunker(bool b) {
	if (b) return xBunker;
	else return yBunker;
}
