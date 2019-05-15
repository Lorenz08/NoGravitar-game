#include "Bullets.h"


Bullets::Bullets(int x, int y)
{
	xBullets = x;
	yBullets = y;
}

int Bullets::getCoordinate(bool g) {
	if (g == true)
		return xBullets;
	else
		return yBullets;
}

void Bullets::setCoordinate(int x, int y) {
	xBullets = x;
	yBullets = y;
}