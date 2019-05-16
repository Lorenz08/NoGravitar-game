#pragma once
#include "Mapp.h"
#include "Spaceship.h"
#include "Bunker1.h"
#include "Bunker2.h"
#include "BulletsList.h"



class PlanetSurface : public Mapp{
public:
	PlanetSurface(Spaceship spaceship, ptr_listaBunker1 &head, ptr_listaBunker2& head2);
	void setMappPlanetSurface(Spaceship &p, char n, bool& b);
	char interationSpaceshipPlanetSurface(Spaceship& p, ptr_listaBunker1& head1, ptr_listaBunker2& head2);
	void raggioTraenteUscente(Spaceship &p);
	void raggioTraenteEntrante(Spaceship p);
	ptr_listaBunker1 creaBunkerList1(ptr_listaBunker1 head, int xB, int yB);
	ptr_listaBunker2 creaBunkerList2(ptr_listaBunker2 head, int xB, int yB);
	void spostamentoPlaetSurface(char& moveSpaceshipUniverso);
	void addBullets(Spaceship &p);
	ptr_Bullets deleteBullets(ptr_Bullets &p);
	void refresh(Spaceship &p, ptr_listaBunker1& head1, ptr_listaBunker2& head2);
};
typedef PlanetSurface* ptr_PlanetSurface;

