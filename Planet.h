
class Planet {
protected:
	int x = 20;
	int y = 80;
	char matrice[20][80]; 

public:
	Planet();
	void printPlanet();
	bool toccaSuperfice(int x, int y, char n);
	void setMatricePlanet(int x, int y, char n);
	void setNavicellaIniziale();
	bool uscitaPianeta(int x, int y, char n);
	
};

