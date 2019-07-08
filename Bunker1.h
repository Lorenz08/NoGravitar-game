#pragma once
#include "BulletsList.h"


typedef class Bunker1* ptr_Bunker1;
struct listaBunker1 {
	Bunker1* b1;
	listaBunker1* next;
};
typedef listaBunker1* ptr_listaBunker1;


class Bunker1{
protected:
	int xBunker1;
	int yBunker1;
	int lifeBunker1;
public:
	ptr_BulletsList LPsx;
	ptr_BulletsList LPdx;
	Bunker1(int x, int y, int life);
	int coordinateBunker1(bool b);
	void minusLife();
	int returnLife();
	void addBulletSBunker1();
	void deleteBulletSBunker1();
	void deleteAllBulletsBunker1();
};
typedef class Bunker1* ptr_Bunker1;


