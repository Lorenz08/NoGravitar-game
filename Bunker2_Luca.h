#pragma once
#include"BulletsList.h"

typedef class Bunker2* ptr_Bunker2;
struct listaBunker2 {
	ptr_Bunker2 b2;
	listaBunker2* next;
	listaBunker2* prev;
};
typedef listaBunker2* ptr_listaBunker2;


class Bunker2 {
protected:
	int xBunker2;
	int yBunker2;
	int lifeBunker2;
	ptr_Bullets proiettile;
public:
	Bunker2(int x, int y, int life);
	int coordinateBunker2(bool b);
	void minusLife();
	int returnLife();
	ptr_Bullets returnPointer(); //SERVE PER FARMI RITORNARE IL PUNTATORE DEI PROIETTILI (IN PLANET_SURFACE)
	void setPointer(ptr_Bullets p); //MI SERVE PER MODIFICARE IL PUNTATORE (IN PLANET_SURFACE)
};
typedef class Bunker2* ptr_Bunker2;