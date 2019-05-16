
#pragma once
#include "Mapp.h"
#include "Spaceship.h"
#include "Bullets.h"
#include "Bunker1.h"
#include "Bunker2.h"



class PlanetSurface : public Mapp {
protected:
	ptr_listaBullets punt;
public:
	PlanetSurface(Spaceship spaceship, ptr_listaBunker1& head, ptr_listaBunker2& head2);
	void setMappPlanetSurface(Spaceship& p, char n, bool& b);
	char interationSpaceshipPlanetSurface(Spaceship& p);
	void raggioTraenteUscente(Spaceship& p);
	void raggioTraenteEntrante(Spaceship p);
	ptr_listaBunker1 creaBunkerList1(ptr_listaBunker1 head, int xB, int yB);
	ptr_listaBunker2 creaBunkerList2(ptr_listaBunker2 head, int xB, int yB);
	void spostamentoPlaetSurface(char& moveSpaceshipUniverso);

	void addBullets(int x, int y);
	ptr_listaBullets deleteBullets(ptr_listaBullets);
	void refresh(int incremento);
};
typedef PlanetSurface* ptr_PlanetSurface;
