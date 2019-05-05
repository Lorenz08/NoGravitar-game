#pragma once
class Mapp{
protected:
	int x = 20;
	int y = 101;
	char matrice[20][101]; //mappa
public:
	Mapp();
	void setMapp();
	void setParametriGiocoUniverso(int fuel, int life);
	void setParametriGiocoPlanet(int fuel, int life);
	void setInitiallyParameters(int fuel, int life);
	void printMapp();
	void setFinalMapp();
	void setInitialMapp();
};

