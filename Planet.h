#include "Mapp.h"
class Planet : public Mapp{
public:
	Planet();
	bool toccaCornice(int x, int y);
	bool toccaSuperficie(int, int y, char m);
	void newSpaceshipPositionPlanet(int x, int y, char n);
	void setNavicellaIniziale();
	bool uscitaPianeta(int x, int y, char n);
	bool raggioTraenteUscente(int x, int y, int n);
	void raggioTraenteEntrante(int x, int y, int n);
	
};

