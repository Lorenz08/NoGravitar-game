
typedef class Planet* ptr_planet;

struct Pianeta {
	int numeroMondo;
	int xCoordinataMondo;
	int yCoordinataMondo;
	bool pianetaDistrutto;
	ptr_planet pianetaCorrente;
	Pianeta* next;
	Pianeta* prev;
};
typedef Pianeta* ptr_Pianeta;


struct Universo {
	ptr_Pianeta PP;
	Universo* next;
	Universo* prev;
};
typedef Universo* ptr_Universo;


#include "Mapp.h"
class Infinito : public Mapp{
protected:
	ptr_Universo puntatoreOggettoUniverso;

public:
	Infinito();
	void aggiungereUniverso();
	void crezioneUniverso(int numeroPianeti);
	void setMappUniverso(int xSpaceship, int ySpaceship, int fuel, int vitaSpaceship);
	bool newSpaceshipPosition(int x, int y, char direzione, int fuel, int vitaSpaceship);
	void aggiungiPlanet();
	ptr_planet pianetaCor(int x, int y);
};
typedef Infinito *ptr_Infinito;




