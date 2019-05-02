
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


class Infinito{
protected:
	int x = 20;
	int y = 80;
	char matrice[20][80]; //mappa

	ptr_Universo puntatoreOggettoUniverso;

public:
	Infinito();
	void aggiungereUniverso();
	void crezioneUniverso(int numeroPianeti);
	void setMappaUniverso(int x, int y);
	bool setMatrice(int x, int y, char direzione);
	void printMappUniverso();
	void aggiungiPlanet();
	void stampaCoordinate();
	ptr_planet pianetaCor(int x, int y);


};
typedef Infinito *ptr_Infinito;




