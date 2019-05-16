#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "SolarSystem.h"
#include "Mapp.h"
#include "PlanetSurface.h"
#include "Spaceship.h"
using namespace std;

int main() {
	Mapp mapp = Mapp(); 
	mapp.printMapp(1);
	char k = '2';
	while (k != VK_RETURN) k = _getch();

	etichetta:
	Spaceship nav_SS = Spaceship();
	SolarSystem x = SolarSystem(nav_SS);
	bool planetEnter = false;
	int numeroSS = 1;
	ptr_listaBunker1 b11 = NULL;
	ptr_listaBunker2 b22 = NULL;


	while (nav_SS.spaceshipIsAlive()) {
		//if (x.returnIfDestroyed()) x.addSolarSystem(nav_SS);
		x.setMappUniverso(nav_SS);
		x.printMapp();
		char n = x.interationSpaceship(nav_SS, planetEnter, numeroSS);
		b11 = x.ritornaBunkerList1(nav_SS, n);
		b22 = x.ritornaBunkerList2(nav_SS, n);
		while ((planetEnter) && (nav_SS.spaceshipIsAlive())) {
			x.pianetaCor(nav_SS, n)->printMapp();
			char m = x.pianetaCor(nav_SS, n)->interationSpaceshipPlanetSurface(nav_SS, b11, b22);
			x.pianetaCor(nav_SS, n)->setMappPlanetSurface(nav_SS, m, planetEnter);
			nav_SS.fuelMinus();
		}
		x.solarSystemChange(numeroSS);
	}
	mapp.printMapp(2);
	char h = '2';
	while (h != 'n') {
		if (h == 's')	goto etichetta;
		else h = _getch();
	}
	return 0;
}