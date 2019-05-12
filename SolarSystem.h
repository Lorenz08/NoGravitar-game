#pragma once
#include "PlanetSurface.h"
#include "Mapp.h"
#include "Spaceship.h"
#include "Bunker.h"


struct Planet {
	int numberPlanet;
	int xPlanet;
	int yPlanet;
	ptr_PlanetSurface planetSurface;
	ptr_listaBunker bunkerList;
	Planet* next;
	Planet* prev;
};
typedef Planet* ptr_Planet;

struct SS {
	int numberSolarSystem;
	ptr_Planet puntatore_planet;
	bool completed;
	Spaceship ssp;
	SS* next;
	SS* prev;
};
typedef SS* ptr_SS;

class SolarSystem : public Mapp {
public:
	SS* SSystem;

	SolarSystem(Spaceship p);
	void addSolarSystem(Spaceship p);
	ptr_Planet creaListaPianeti(Spaceship p, ptr_Planet head, int u);
	void xxx();
	void xxx2();
	void setMappUniverso();
	void interationSpaceship(char n, bool &b, int &numeroSS);
	ptr_PlanetSurface pianetaCor(char n);
	bool solarSystemDestroyed();
	void solarSystemChange(int i);
	bool returnIfDestroyed();
};

