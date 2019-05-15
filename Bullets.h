#pragma once

typedef class Bullets* ptr_Bullets;
struct listaBullets {
	ptr_Bullets b;
	int xCoordinate;
	int yCoordinate;
	char sparo;
	bool eliminato;
	listaBullets* next;
};
typedef listaBullets* ptr_listaBullets;


class Bullets
{
protected:
	int xBullets;
	int yBullets;

public:
	Bullets(int x, int y);
	int getCoordinate(bool g);
	void setCoordinate(int x, int y);
};

