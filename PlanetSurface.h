#pragma once
#include "Mapp.h"
#include "Spaceship.h"
#include "Bunker.h"



class PlanetSurface : public Mapp{
public:
	PlanetSurface(Spaceship spaceship, ptr_listaBunker &head);
	void setMappPlanetSurface(Spaceship &p, char n, bool& b);
	void interationSpaceship2(Spaceship& p, char n);
	void raggioTraenteUscente(Spaceship &p);
	void raggioTraenteEntrante(Spaceship p);
	ptr_listaBunker creaBunkerList(ptr_listaBunker head, int xB, int yB);
};
typedef PlanetSurface* ptr_PlanetSurface;

