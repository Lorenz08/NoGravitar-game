#include <iostream>
#include "Mapp.h"
#include <conio.h>
#include "Spaceship.h"
#include "Universe.h"
#include "Planet.h"
#include <ctime>
#include <cstdlib>



using namespace std;

struct Pianeta {
	int n;
	int x;
	int y;
};

struct Universo {
	Pianeta p;
	Universo *next;
	Universo *prev;
};
typedef Universo *ptr_Universo;

Universe::Universe():Mapp{


}


ptr_Universo Universe::creazioneLista(ptr_Universo head){

	Pianeta onePlanet = { 1, ((rand() % 9) + 1), ((rand() % 38) + 1) };
	Pianeta twoPlanet = { 2, ((rand() % 9) + 11), ((rand() % 38) + 1) };
	Pianeta threePlanet = { 3, ((rand() % 9) + 21), ((rand() % 38) + 1) };
	Pianeta fourPlanet = { 4, ((rand() % 9) + 31), ((rand() % 38) + 1) };
	Pianeta fivePlanet = { 5, ((rand() % 9) + 41), ((rand() % 38) + 1) };
	Pianeta sixPlanet = { 6, ((rand() % 9) + 51), ((rand() % 38) + 1) };
	Pianeta sevenPlanet = { 7, ((rand() % 9) + 61), ((rand() % 38) + 1) };
	Pianeta eightPlanet = { 8, ((rand() % 9) + 71), ((rand() % 38) + 1) };


	head = new Universo;
	head->p = onePlanet;
	head->next = NULL;
	head->prev = NULL;



	ptr_Universo tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8;
	ptr_Universo tmpOld2, tmpOld3, tmpOld4, tmpOld5, tmpOld6, tmpOld7, tmpOld8;
	tmp2 = head;
	while (tmp2->next != NULL) tmp2 = tmp2->next;
	tmp2->next = new Universo;
	tmp2->p = twoPlanet;
	tmp2->prev = head->next;
	tmp2->next = NULL;

	tmp3 = head;
	tmpOld3 = head;
	while (tmp3->next != NULL) tmp3 = tmp3->next;
	while (tmpOld3->next->next != NULL) tmpOld3 = tmpOld3->next;
	tmp3->next = new Universo;
	tmp3->p = threePlanet;
	tmp3->prev = tmpOld3;
	tmp3->next = NULL;

	tmp4 = head;
	tmpOld4 = head;
	while (tmp4->next != NULL) tmp4 = tmp4->next;
	while (tmpOld4->next->next != NULL) tmpOld4 = tmpOld4->next;
	tmp4->next = new Universo;
	tmp4->p = fourPlanet;
	tmp4->prev = tmpOld4;
	tmp4->next = NULL;

	tmp5 = head;
	tmpOld5 = head;
	while (tmp5->next != NULL) tmp5 = tmp5->next;
	while (tmpOld5->next->next != NULL) tmpOld5 = tmpOld5->next;
	tmp5->next = new Universo;
	tmp5->p = fivePlanet;
	tmp5->prev = tmpOld5;
	tmp5->next = NULL;

	tmp6 = head;
	tmpOld6 = head;
	while (tmp6->next != NULL) tmp6 = tmp6->next;
	while (tmpOld6->next->next != NULL) tmpOld6 = tmpOld6->next;
	tmp6->next = new Universo;
	tmp6->p = sixPlanet;
	tmp6->prev = tmpOld6;
	tmp6->next = NULL;

	tmp7 = head;
	tmpOld7 = head;
	while (tmp7->next != NULL) tmp7 = tmp7->next;
	while (tmpOld7->next->next != NULL) tmpOld7 = tmpOld7->next;
	tmp7->next = new Universo;
	tmp7->p = sevenPlanet;
	tmp7->prev = tmpOld7;
	tmp7->next = NULL;

	tmp8 = head;
	tmpOld8 = head;
	while (tmp8->next != NULL) tmp8 = tmp8->next;
	while (tmpOld8->next->next != NULL) tmpOld8 = tmpOld8->next;
	tmp8->next = new Universo;
	tmp8->p = sevenPlanet;
	tmp8->prev = tmpOld8;
	tmp8->next = NULL;

	return head;
}

void Universe::numbersPlanet(ptr_Universo inizioLista) {
	srand((unsigned)time(0));
	int numeroMondi = ((rand() %4 ) + 5);
	ptr_Universo tmp = inizioLista;
	for (int i = 0; i < numeroMondi; i++) tmp = tmp->next;
	tmp->next = NULL;
}