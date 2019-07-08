#pragma once

struct Bullet {
	int xBullet;
	int yBullet;
	bool eliminato;
	Bullet* next;
};
typedef Bullet* ptr_Bullet;

class BulletsList {
public:
	ptr_Bullet listaProiettili;
	BulletsList();
	void addBullets(int x, int y, bool b);
	void deleteBullets();
};
typedef class BulletsList* ptr_BulletsList;