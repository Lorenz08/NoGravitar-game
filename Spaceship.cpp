#include <conio.h>
#include <iostream>
#include "Spaceship.h"
#include "Infinito.h"

using namespace std;

//crea la navicella e setta la sua posizione iniziale 
Spaceship::Spaceship()
{
	p1 = 3;
	p2 = 3;

	p3 = 3;
	p4 = 3;

	life = 5;
	fuel = 2000;
}


//modifica la nuova posizione della navicella
//prima di modificare le coordinate della navicella, fa un controllo per evitare che esca dalla mappa
//(evita la sovrapposizione della navicella con i margini)
void Spaceship::moveSpaceship(char n) {
	if (n == 75 && p2 > 1)          p2 = p2 - 1;			//SINISTRA---controllo margine
	else if (n == 77 && p2 < 78)    p2 = p2 + 1;        	//DESTRA---controllo margine
	else if (n == 72 && p1 > 1) 	p1 = p1 - 1;	        //SU---controllo marigine
	else if (n == 80 && p1 < 18)	p1 = p1 + 1;	        //GIU---controllo margine
}


void Spaceship::moveSpaceshipPlanet(char m) {
	if (m == 75 && p4 > 0) {  //SINISTRA---controllo margine
		p4 = p4 - 1;
		//fuel--;
	}
	else if (m == 77 && p4 < 79) {   //DESTRA---controllo margine
		p4 = p4 + 1;
		//fuel--;
	}
	else if (m == 72) {  //qui non c'è il controllo margine perche dal lato superiore si esce dal pianeta
		p3 = p3 - 1;
		//if (p3 >= 1) fuel--;
	}
	else if (m == 80 && p3 < 18) {  //GIU---controllo margine
		p3 = p3 + 1;
		//fuel--;
	}
}


int Spaceship::coordinate(bool scelta) {
	if (scelta == true) return p1;
	else return p2;
}

int Spaceship::coordinatePlanet(bool scelta) {
	if (scelta == true) return p3;
	else return p4;
}

void Spaceship::rispristinoCoordinateInCasoDiPianeta(bool b, char n) {
	if (b == true) {
		if (n == 75)      p2 = p2 + 1;
		else if (n == 77) p2 = p2 - 1;
		else if (n == 72) p1 = p1 + 1;
		else if (n == 80) p1 = p1 - 1;
	}
}

void Spaceship::rispristinoCoordinateInCasoDisuperficie(bool b, char n) {
	if (b == true) {
		if (n == 75)      p4 = p4 + 1;
		else if (n == 77) p4 = p4 - 1;
		else if (n == 72) p3 = p3 + 1;
		else if (n == 80) p3 = p3 - 1;
	}
}

void Spaceship::perditaVitaInCasosuperficie(bool b) {
	if (b) life--;
}

void Spaceship::ripristinoCoordinateUscitaPianeta() {
	p3 = 3;
	p4 = 3;
}


void Spaceship::raggioTraente() {
	if (p4 + 1 != ' ') fuel = fuel + 100;
}

