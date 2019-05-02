class Mapp {
protected:
	int x;
	int y;
	char matrice[20][80]; //mappa

public:
	Mapp();
	bool setMatrice(int x, int y, char n);
	void printMapp();
};
