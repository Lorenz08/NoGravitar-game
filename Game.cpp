#include <iostream>
#include "Game.h"
using namespace std;

Game::Game(int f, int l) {
	fuel = f;
	life = l;
}

void Game::aggiornaParametri(int f, int l) {
	fuel = f;
	life = l;
}

bool Game::boolGame() {
	if (fuel <= 0) return false;
	if (life <= 0) return false;
	else return true;
}




