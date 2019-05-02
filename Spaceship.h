class Spaceship {
public:
	int p1;  //coordinate x della navicella
	int p2;  //coordinate y della navicella
	int p3;
	int p4;

public:
	Spaceship();
	char moveSpaceship();
	char moveSpaceshipPlanet();
	int coordinate(bool scelta);
	int coordinatePlanet(bool scelta);
};