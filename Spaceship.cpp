#include <conio.h>
#include <iostream>
#include "Spaceship.h"
#include "Mapp.h"
using namespace std;

//crea la navicella e setta la sua posizione iniziale 
Spaceship::Spaceship()
{
	p1 = 2;
	p2 = 2;
	p3 = 5;
	p4 = 5;
}


//modifica la nuova posizione della navicella
//prima di modificare le coordinate della navicella, fa un controllo per evitare che esca dalla mappa
//(evita la sovrapposizione della navicella con i margini)
char Spaceship::moveSpaceship() {
	char n;
	n = _getch(); // prende in input senza premere invio

	if (n == 75 && p2 > 1)          p2 = p2 - 1;			//SINISTRA---controllo margine
	else if (n == 77 && p2 < 78)    p2 = p2 + 1;        	//DESTRA---controllo margine
	else if (n == 72 && p1 > 1) 	p1 = p1 - 1;	        //SU---controllo marigine
	else if (n == 80 && p1 < 18)	p1 = p1 + 1;	        //GIU---controllo margine
	return n;
}

char Spaceship::moveSpaceshipPlanet() {
	char m;
	m = _getch(); // prende in input senza premere invio

	if (m == 75 && p4 > 1)          p4 = p4 - 1;			//SINISTRA---controllo margine
	else if (m == 77 && p4 < 78)    p4 = p4 + 1;        	//DESTRA---controllo margine
	else if (m == 72 && p3 > 1) 	p3 = p3 - 1;	        //SU---controllo marigine
	else if (m == 80 && p3 < 18)	p3 = p3 + 1;	        //GIU---controllo margine
	return m;
}


int Spaceship::coordinate(bool scelta) {
	if (scelta == true) return p1;
	else return p2;
}

int Spaceship::coordinatePlanet(bool scelta) {
	if (scelta == true) return p3;
	else return p4;
}