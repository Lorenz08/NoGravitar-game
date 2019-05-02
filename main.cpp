#include <iostream>
#include <ctime>
#include <conio.h>
#include "Infinito.h"
#include "Spaceship.h"
#include "Planet.h"


using namespace std;

int main() {
	srand((unsigned)time(0));

	Infinito uno = Infinito();   //oggetto inziale
	Spaceship nav_SistemaSolare = Spaceship();  //ogetto di tipo navicella usata nel sistema solare
	Spaceship nav_Pianeta = Spaceship();        //oggetto di tipo navicella usata all'interno di un pianeta

	//crea la struttura principale
	//inizialmente crea l'universo iniziale, poi attraverso un numero random gli collega una lista di pianeti che faranno parte do quel sistema solare
	//setta la mappa del sistema solare in modo visivo, inserendo la cornice, i vari pianeti nella loro posizione e la posizione iniziale della navicella_sistemaSolare
	uno.aggiungereUniverso();                   
	int numeroPianeti = ((rand() % 4) + 5);   
	uno.crezioneUniverso(7);
	uno.setMappaUniverso(nav_SistemaSolare.coordinate(true), nav_SistemaSolare.coordinate(false));   //coordinate della navicella passate come parametro

	while (1) {
		bool b = false;
		uno.printMappUniverso();        //stampa la mappa dell'universo prcedentemente settata
		char m = nav_SistemaSolare.moveSpaceship();   //attraverso un char inserito da tastiera si modificano le coordinate della navicella cosi poi da stamparla in posizione diversa al momento del nuovo settaggio della mappa (siccome le coordinate sono passate come parametro)
		b = uno.setMatrice(nav_SistemaSolare.coordinate(true), nav_SistemaSolare.coordinate(false), m);
		if (b == true) {
			uno.pianetaCor(nav_SistemaSolare.coordinate(true), nav_SistemaSolare.coordinate(false))->setNavicellaIniziale();
			char k = ' ';
			while (uno.pianetaCor(nav_SistemaSolare.coordinate(true), nav_SistemaSolare.coordinate(false))->uscitaPianeta(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), k)) {
				uno.pianetaCor(nav_SistemaSolare.coordinate(true), nav_SistemaSolare.coordinate(false))->printPlanet();
				k = nav_Pianeta.moveSpaceshipPlanet();
				if (uno.pianetaCor(nav_SistemaSolare.coordinate(true), nav_SistemaSolare.coordinate(false))->toccaSuperfice(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), k)) {
					uno.pianetaCor(nav_SistemaSolare.coordinate(true), nav_SistemaSolare.coordinate(false))->setMatricePlanet(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), k);
				}
				else nav_Pianeta.rispristinoCoordinateInCasoDiSuperfice(uno.pianetaCor(nav_SistemaSolare.coordinate(true), nav_SistemaSolare.coordinate(false))->uscitaPianeta(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), k), k);
			}
		}
		nav_Pianeta.ripristinoCoordinateUscitaPianeta();
		nav_SistemaSolare.rispristinoCoordinateInCasoDiPianeta(b, m);
	}
	


	

	



	return 0;
}
