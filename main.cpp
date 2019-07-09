#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include "SolarSystem.h"
#include "Mapp.h"
#include "PlanetSurface.h"
#include "Spaceship.h"
#include "BulletsList.h"
using namespace std;

int main() {
	srand((unsigned)time(0));
	Mapp mapp = Mapp(); 
	mapp.printMapp(1,1);
	char k = '2';
	while (k != VK_RETURN) k = _getch();

	etichetta:
	Spaceship nav_SS = Spaceship();
	SolarSystem x = SolarSystem(nav_SS);
	if (x.ifPianetiSovrapposti()) goto etichetta;  //controlla se la funzione random a creato piu piantei con le stesse coordiante (sovrapposti)
	bool planetEnter = false;
	bool pianetaDistrutto = false;
	int numeroSS = 1;
	int cicloSpari = 0;
	bool trashBullets = true;

	while (nav_SS.spaceshipIsAlive()) {
		x.setMappUniverso(nav_SS);
		x.printMapp();
		char n = x.interationSpaceship(nav_SS, planetEnter, numeroSS);
		while ((planetEnter) && (nav_SS.spaceshipIsAlive())) {
			x.pianetaCor(nav_SS, n)->azzerareListeBullets(nav_SS, trashBullets);
			x.pianetaCor(nav_SS, n)->printMapp();
			char m = x.pianetaCor(nav_SS, n)->interationSpaceshipPlanetSurface(nav_SS, pianetaDistrutto);
			x.pianetaCor(nav_SS, n)->sparaBunker(nav_SS, cicloSpari);
			x.xxx(nav_SS, n, x.pianetaCor(nav_SS, n)->ritornoBunkerList1(), x.pianetaCor(nav_SS, n)->ritornoBunkerList2());
			x.pianetaCor(nav_SS, n)->setMappPlanetSurface(nav_SS, m, planetEnter);
			nav_SS.fuelMinus();
		}
		trashBullets = true;
		x.solarSystemChange(numeroSS);
	}

	mapp.printMapp(2,1);
	char h = '2';
	while (h != 'n') {
		if (h == 'y')	goto etichetta;
		else h = _getch();
	}
	mapp.printMapp(3, 1);
	return 0;
}