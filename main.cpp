#include <iostream>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include "Infinito.h"
#include "Spaceship.h"
#include "Planet.h"
#include "Mapp.h"
#include "Game.h"
#include <WinUser.h>


using namespace std;

int main() {
	srand((unsigned)time(0));

	Mapp initial = Mapp();
	Mapp final = Mapp();
	Infinito uno = Infinito();   //oggetto inziale
	Spaceship nav_SS = Spaceship();  //ogetto di tipo navicella usata nel sistema solare
	Spaceship nav_Pianeta = Spaceship();        //oggetto di tipo navicella usata all'interno di un pianeta
	Game gioco = Game(nav_Pianeta.fuel, nav_Pianeta.life);

	initial.setInitialMapp();
	initial.printInitialMapp();
	
	char k = ' ';
	while (k != 'y') k = _getch();


	//crea la struttura principale
	//inizialmente crea l'universo iniziale, poi attraverso un numero random gli collega una lista di pianeti che faranno parte do quel sistema solare
	//setta la mappa del sistema solare in modo visivo, inserendo la cornice, i vari pianeti nella loro posizione e la posizione iniziale della navicella_sistemaSolare
	uno.aggiungereUniverso();
	int numeroPianeti = ((rand() % 4) + 5);
	uno.crezioneUniverso(numeroPianeti);  //crea l'universo con un numero di pianeti casuali 
	uno.setMappUniverso(nav_SS.coordinate(true), nav_SS.coordinate(false), nav_SS.fuel, nav_Pianeta.life);   //coordinate della navicella passate come parametro
	int raggio = 1;  //raggio traente 
	bool guardiaRaggio = true;    //consente il movimento della navicella quando il raggio traente viene attivato
	
	while (gioco.boolGame()) {
		uno.setInitiallyParameters(nav_Pianeta.fuel, nav_Pianeta.life);  //setta i parametri iniziali di vita e carburante
		uno.printMapp();           //stampa la mappa dell'universo prcedentemente settata
		
		char moveSpaceshipUniverso = ' ';
		if (GetAsyncKeyState(VK_UP)) moveSpaceshipUniverso = 72;
		else if (GetAsyncKeyState(VK_LEFT)) moveSpaceshipUniverso = 75;
		else if (GetAsyncKeyState(VK_RIGHT)) moveSpaceshipUniverso = 77;
		else if (GetAsyncKeyState(VK_DOWN)) moveSpaceshipUniverso = 80;
		nav_SS.moveSpaceship(moveSpaceshipUniverso);   //attraverso un char inserito da tastiera si modificano le coordinate della navicella cosi poi da stamparla in posizione diversa al momento del nuovo settaggio della mappa (siccome le coordinate sono passate come parametro)
	
		bool planetEnter = uno.newSpaceshipPosition(nav_SS.coordinate(true), nav_SS.coordinate(false), moveSpaceshipUniverso, nav_Pianeta.fuel, nav_Pianeta.life);  //si setta la nuova posizione della navicella e con un booleano si indica se si è entrato in un pianeta o meno
		
		if (planetEnter == true) {
			uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->setNavicellaIniziale();  //setta la posizione della navicella all'interno del pianeta
			char tastoPremuto = ' ';     //tasto iniziale vuoto
			while ((uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->uscitaPianeta(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), tastoPremuto)) && (gioco.boolGame())) {  //cpntrolla se la posizione della navicella è nella prima riga, in tal caso vuol dire che è uscita dal pianeta
				uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->setParametriGiocoPlanet(nav_Pianeta.fuel, nav_Pianeta.life);  //setta i nuovi parametri di gioco nella schermata
				uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->printMapp();   //stampa il pianeta
				
				if (GetAsyncKeyState(0x51)) tastoPremuto = 'q';
				else if ((guardiaRaggio) && (GetAsyncKeyState(VK_UP))) tastoPremuto = 72;
				else if ((guardiaRaggio) && (GetAsyncKeyState(VK_LEFT))) tastoPremuto = 75;
				else if ((guardiaRaggio) && (GetAsyncKeyState(VK_RIGHT))) tastoPremuto = 77;
				else if ((guardiaRaggio) && (GetAsyncKeyState(VK_DOWN))) tastoPremuto = 80;
				if (!guardiaRaggio) tastoPremuto = 'w';

				if (tastoPremuto == 'q') {  //controlla che il raggio non tocchi la superficie e se verificato per ogni tasto 'q' premuto esce un pezzetto di raggio
					int distanza = 0;
					while (uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->spazioPerRaggio(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), raggio)) {
						guardiaRaggio = false;  //blocca il movimento della navicella
						uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->raggioTraenteUscente(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), raggio, distanza);
						raggio++;  //aumenta di una casella il raggio traente in caso venga premuto nuovamente il tasto 'q'
					}
					uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->presenzaCarburante(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), distanza, nav_Pianeta.fuel);
					distanza = 0;
				}

				else if (tastoPremuto == 'w') {
					uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->raggioTraenteEntrante(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), raggio); //elimina tutto il raggio traente
					raggio = 1;  //riprstina il raggio traente a 1
					tastoPremuto = ' ';
					guardiaRaggio = true;  //sblocca il movimento della navicella 
				}

				else if (guardiaRaggio) {
					nav_Pianeta.moveSpaceshipPlanet(tastoPremuto);  //modifica coordinate della navicella
					if (uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->toccaCornice(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false))) {
						uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->newSpaceshipPositionPlanet(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), tastoPremuto);  //dopo aver fatto il controllo per vedere se la navicella si muove in una casella con carattere vuoto, setta la nuova posizione della navicella 
						tastoPremuto = ' ';
					}
					else {
						//viene settata la posizione della navicella alla posizione precedente
						//in caso la casella contenga un carattere non vuoto, se contiene uno che compone la superficie allora viene tolta una vita
						nav_Pianeta.perditaVitaInCasosuperficie(uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->toccaSuperficie(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), tastoPremuto));
						gioco.aggiornaParametri(nav_Pianeta.fuel, nav_Pianeta.life);
						nav_Pianeta.rispristinoCoordinateInCasoDisuperficie(uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->uscitaPianeta(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), tastoPremuto), tastoPremuto);
						if (uno.pianetaCor(nav_SS.coordinate(true), nav_SS.coordinate(false))->toccaSuperficie(nav_Pianeta.coordinatePlanet(true), nav_Pianeta.coordinatePlanet(false), tastoPremuto)) tastoPremuto = ' ';
					}
				}
				nav_Pianeta.fuel--;
			}
		}
		nav_Pianeta.ripristinoCoordinateUscitaPianeta();    //rirpistina le coordinate della navicella del pianeta ad un punto fissato cosi che quando si entri in un pianeta parti sempre dallo stesso punto 
		nav_SS.rispristinoCoordinateInCasoDiPianeta(planetEnter, moveSpaceshipUniverso);  //ripristina le coordinate della navicella del sistema solarepresenti prima di entrare all'interno del pianeta (cosi da non scrovrascrivere la 'O' indicante i pianeti)
	}


	final.setFinalMapp();
	final.printMapp();



	return 0;
}