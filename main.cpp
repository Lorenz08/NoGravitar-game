#include <iostream>
#include "Mapp.h"
#include "Spaceship.h"
#include "Planet.h"
#include "Universe.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void ShowConsoleCursor(bool showFlag)  //funzione per non fare vedere il cursore
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

struct Pianeta {
	int n;
	int x;
	int y;
};

struct Universo {
	SistemaSolare ss;
	Universo *next;
	Universo *prev;
};
typedef Universo *ptr_Universo;

int main() {
	ShowConsoleCursor(false);

	/*Spaceship navi = Spaceship();
	Planet onePlanet = Planet();
	Universe universe = Universe();*/



	//onePlanet.createSurface();


	/*while (1) {

		universe.printMapp();
		char n = navi.moveSpaceship();
		universe.setMatrice(navi.coordinate(true), navi.coordinate(false), n);
		if (universe.setMatrice(navi.coordinate(true), navi.coordinate(false), n) == true) {
			bool t = false;
			while (t == false) {
				onePlanet.printMapp();
				char m = navi.moveSpaceshipPlanet();
				t = onePlanet.uscitaDalPlanet(m);
				onePlanet.setMatrice(navi.coordinatePlanet(true), navi.coordinatePlanet(false), m);
				if (t == true) onePlanet.ripristinaCoordinate();
				
			}
		}
	}*/

	
	ptr_Universo head = NULL;
	Universe bho = Universe();
	head = bho.creazioneLista(head);



	return 0;


}