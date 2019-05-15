
#include <iostream>
#include <conio.h>
#include <Windows.h>
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
	char k = '2';

	mapp.printMapp(1);
	while (k != ' ') k = _getch();
	while (nav_SS.spaceshipIsAlive()) {
		//if (x.returnIfDestroyed()) x.addSolarSystem(nav_SS);
		x.setMappUniverso(nav_SS);
		x.printMapp();
		char n = x.interationSpaceship(nav_SS, planetEnter, numeroSS);
		while ((planetEnter) && (nav_SS.spaceshipIsAlive())) {
			x.pianetaCor(nav_SS, n)->printMapp();
			char m = x.pianetaCor(nav_SS, n)->interationSpaceshipPlanetSurface(nav_SS);
			x.pianetaCor(nav_SS, n)->setMappPlanetSurface(nav_SS, m, planetEnter);
			nav_SS.fuelMinus();
			x.pianetaCor(nav_SS, n)->refresh();
		}
		x.solarSystemChange(numeroSS);
	}
	mapp.printMapp(2);
	return 0;
}