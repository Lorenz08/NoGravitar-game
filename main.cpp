#include <iostream>
#include <conio.h>
#include "SolarSystem.h"
#include "Mapp.h"
#include "PlanetSurface.h"
#include "Spaceship.h"
using namespace std;

int main() {
	Spaceship nav_SS = Spaceship();
	SolarSystem x = SolarSystem(nav_SS);
	Mapp mapp = Mapp();
	bool planetEnter = false;
	int numeroSS = 1;
	char k = ' ';

	mapp.printMapp(1);
	while (k != 'y') k = _getch();
	while (nav_SS.returnParameter(10) >= 1) {
		if (x.returnIfDestroyed()) x.addSolarSystem(nav_SS);
		x.setMappUniverso();
		x.printMapp();
		char n = x.interationSpaceship(planetEnter, numeroSS);
		while (planetEnter && nav_SS.returnParameter(10) >= 1) {
			x.pianetaCor(n)->printMapp();
			char m = x.pianetaCor(n)->interationSpaceshipPlanetSurface(nav_SS);
			x.pianetaCor(n)->setMappPlanetSurface(nav_SS, m, planetEnter);
			nav_SS.fuelMinus();
		}
		x.solarSystemChange(numeroSS);
	}
	mapp.printMapp(2);
	return 0;
}