#pragma once

struct Bullets {
	int xBullet;
	int yBullet;
	bool eliminato;
	Bullets* next;
};
typedef Bullets* ptr_Bullets;



class BulletsList {
protected:
	ptr_Bullets listaProiettili;
public:
	BulletsList();
};
typedef class BulletsList* ptr_BulletsList;
