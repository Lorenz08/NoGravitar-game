#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Mapp.h"
using namespace std;


Mapp::Mapp(){
}


void Mapp::printMapp(int i) {
	if (i == 1) setInitialMapp();
	else if (i == 2) setFinalMapp();
	system("cls");
	ShowConsoleCursor(false);
	const int WIDTH = 101;
	const int HEIGHT = 21;
	SMALL_RECT windowSize = { 0, 0, WIDTH - 1, HEIGHT - 1 };
	COORD bufferSize = { WIDTH , HEIGHT };
	COORD characterBufferSize = { WIDTH , HEIGHT };
	COORD characterPosition = { 0, 0 };
	SMALL_RECT consoleWriteArea = { 0, 0, WIDTH - 1, HEIGHT - 1 };
	CHAR_INFO consoleBuffer[WIDTH * HEIGHT];
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE rHnd = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x) {
			consoleBuffer[x + WIDTH * y].Char.AsciiChar = (unsigned char)matrice[x][y];
			consoleBuffer[x + WIDTH * y].Attributes = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN;
		}
	}
	WriteConsoleOutputA(wHnd, consoleBuffer, characterBufferSize, characterPosition, &consoleWriteArea);
	Sleep(150);
}


void Mapp::setMapp() {
	for (int y = 0; y <= yMatrice; y++) {
		for (int x = 0; x <= xMatrice; x++) {
			matrice[x][y] = ' ';
		}
	}
	matrice[0][0] = 201;
	matrice[0][20] = 200;
	matrice[100][0] = 187;
	matrice[100][20] = 188;
	int i;
	for (i = 1; i < yMatrice; i++)  matrice[0][i] = 186;
	for (i = 1; i < yMatrice; i++)  matrice[xMatrice][i] = 186;
	for (i = 1; i < xMatrice; i++)  matrice[i][0] = 205;
	for (i = 1; i < xMatrice; i++)  matrice[i][yMatrice] = 205;
	for (i = 1; i < yMatrice; i++)  matrice[78][i] = 186;
	for (i = 79; i < 100; i++) matrice[i][7] = 205;
	matrice[78][7] = 204;
	matrice[100][7] = 185;
	matrice[78][0] = 203;
	matrice[78][20] = 202;
}


void Mapp::setGeneralParameters(int fuel, int life) {
	int migliaia = (fuel / 1000);
	int centinaia = ((fuel - (migliaia * 1000)) / 100);
	int decine = ((fuel - (migliaia * 1000) - (centinaia * 100)) / 10);
	int unità = (fuel - (migliaia * 1000) - (centinaia * 100) - (decine * 10));

	matrice[79][1] = 'V';
	matrice[80][1] = 'I';
	matrice[81][1] = 'T';
	matrice[82][1] = 'A';
	matrice[83][1] = ':';
	matrice[84][1] = (char)life + 48;

	matrice[79][3] = 'C';
	matrice[80][3] = 'A';
	matrice[81][3] = 'R';
	matrice[82][3] = 'B';
	matrice[83][3] = 'U';
	matrice[84][3] = 'R';
	matrice[85][3] = 'A';
	matrice[86][3] = 'N';
	matrice[87][3] = 'T';
	matrice[88][3] = 'E';
	matrice[89][3] = ':';
	matrice[90][3] = (char)migliaia + 48;
	matrice[91][3] = (char)centinaia + 48;
	matrice[92][3] = (char)decine + 48;
	matrice[93][3] = (char)unità + 48;

	matrice[89][14] = '^';
	matrice[86][12] = 'F';
	matrice[87][12] = 'R';
	matrice[88][12] = 'E';
	matrice[89][12] = 'C';
	matrice[90][12] = 'C';
	matrice[91][12] = 'I';
	matrice[92][12] = 'A';
	matrice[88][13] = 'S';
	matrice[89][13] = 'U';

	matrice[89][16] = 'v';
	matrice[86][17] = 'F';
	matrice[87][17] = 'R';
	matrice[88][17] = 'E';
	matrice[89][17] = 'C';
	matrice[90][17] = 'C';
	matrice[91][17] = 'I';
	matrice[92][17] = 'A';
	matrice[88][18] = 'G';
	matrice[89][18] = 'I';
	matrice[90][18] = 'U';
	
	matrice[87][15] = '<';
	matrice[79][15] = 'F';
	matrice[80][15] = 'R';
	matrice[81][15] = 'E';
	matrice[82][15] = 'C';
	matrice[83][15] = 'C';
	matrice[84][15] = 'I';
	matrice[85][15] = 'A';
	matrice[81][16] = 'S';
	matrice[82][16] = 'X';

	matrice[91][15] = '>';
	matrice[93][15] = 'F';
	matrice[94][15] = 'R';
	matrice[95][15] = 'E';
	matrice[96][15] = 'C';
	matrice[97][15] = 'C';
	matrice[98][15] = 'I';
	matrice[99][15] = 'A';
	matrice[95][16] = 'D';
	matrice[96][16] = 'X';
}


void Mapp::setSolarSystemParameters(int fuel, int life, int universo) {
	setGeneralParameters(fuel, life);

	matrice[79][5] = 'S';
	matrice[80][5] = '.';
	matrice[81][5] = 'S';
	matrice[82][5] = 'O';
	matrice[83][5] = 'L';
	matrice[84][5] = 'A';
	matrice[85][5] = 'R';
	matrice[86][5] = 'E';
	matrice[87][5] = ':';
	matrice[88][5] = (char)universo + 48;
}


void Mapp::setPlanetSurfaceParameters(int fuel, int life) {
	setGeneralParameters(fuel, life); 

	matrice[79][8] = 'q';
	matrice[80][8] = ':';
	matrice[81][8] = 'A';
	matrice[82][8] = 'T';
	matrice[83][8] = 'T';
	matrice[84][8] = 'I';
	matrice[85][8] = 'V';
	matrice[86][8] = 'A';
	matrice[87][8] = 'R';
	matrice[88][8] = 'E';
	matrice[89][8] = ' ';
	matrice[90][8] = 'R';
	matrice[91][8] = 'A';
	matrice[92][8] = 'G';
	matrice[93][8] = 'G';
	matrice[94][8] = 'I';
	matrice[95][8] = 'O';

	matrice[79][9] = 'w';
	matrice[80][9] = ':';
	matrice[81][9] = 'A';
	matrice[82][9] = 'N';
	matrice[83][9] = 'N';
	matrice[84][9] = 'U';
	matrice[85][9] = 'L';
	matrice[86][9] = 'L';
	matrice[87][9] = 'A';
	matrice[88][9] = 'R';
	matrice[89][9] = 'E';
	matrice[90][9] = ' ';
	matrice[91][9] = 'R';
	matrice[91][9] = 'A';
	matrice[93][9] = 'G';
	matrice[94][9] = 'G';
	matrice[95][9] = 'I';
	matrice[96][9] = 'O';

	matrice[79][10] = 's';
	matrice[80][10] = 'p';
	matrice[81][10] = 'a';
	matrice[82][10] = 'c';
	matrice[83][10] = 'e';
	matrice[84][10] = ':';
	matrice[85][10] = 'S';
	matrice[86][10] = 'P';
	matrice[87][10] = 'A';
	matrice[88][10] = 'R';
	matrice[89][10] = 'A';
	matrice[90][10] = 'R';
	matrice[91][10] = 'E';
}


void Mapp::setInitialMapp() {
	for (int y = 0; y <= yMatrice; y++) {
		for (int x = 0; x <= xMatrice; x++) {
			matrice[x][y] = ' ';
		}
	}
	matrice[0][0] = 201;
	matrice[0][20] = 200;
	matrice[100][0] = 187;
	matrice[100][20] = 188;
	int i;
	for (i = 1; i < yMatrice; i++)  matrice[0][i] = 186;
	for (i = 1; i < yMatrice; i++)  matrice[xMatrice][i] = 186;
	for (i = 1; i < xMatrice; i++)  matrice[i][0] = 205;
	for (i = 1; i < xMatrice; i++)  matrice[i][yMatrice] = 205;

	matrice[48][9] = 'N';
	matrice[49][9] = 'O';
	matrice[50][9] = ' ';
	matrice[51][9] = 'G';
	matrice[52][9] = 'R';
	matrice[53][9] = 'A';
	matrice[54][9] = 'V';
	matrice[55][9] = 'I';
	matrice[56][9] = 'T';
	matrice[57][9] = 'A';
	matrice[58][9] = 'R';

	matrice[44][10] = 'P';
	matrice[45][10] = 'r';
	matrice[46][10] = 'e';
	matrice[47][10] = 'm';
	matrice[48][10] = 'e';
	matrice[49][10] = 'r';
	matrice[50][10] = 'e';
	matrice[51][10] = ' ';
	matrice[52][10] = 't';
	matrice[53][10] = 'a';
	matrice[54][10] = 's';
	matrice[55][10] = 't';
	matrice[56][10] = 'o';
	matrice[57][10] = ' ';
	matrice[58][10] = 'i';
	matrice[59][10] = 'n';
	matrice[60][10] = 'v';
	matrice[61][10] = 'i';
	matrice[62][10] = 'o';
}


void Mapp::setFinalMapp() {
	for (int y = 0; y <= yMatrice; y++) {
		for (int x = 0; x <= xMatrice; x++) {
			matrice[x][y] = ' ';
		}
	}
	matrice[0][0] = 201;
	matrice[0][20] = 200;
	matrice[100][0] = 187;
	matrice[100][20] = 188;
	int i;
	for (i = 1; i < yMatrice; i++)  matrice[0][i] = 186;
	for (i = 1; i < yMatrice; i++)  matrice[xMatrice][i] = 186;
	for (i = 1; i < xMatrice; i++)  matrice[i][0] = 205;
	for (i = 1; i < xMatrice; i++)  matrice[i][yMatrice] = 205;

	matrice[48][9] = 'G';
	matrice[49][9] = 'A';
	matrice[50][9] = 'M';
	matrice[51][9] = 'E';
	matrice[52][9] = ' ';
	matrice[53][9] = '0';
	matrice[54][9] = 'V';
	matrice[55][9] = 'E';
	matrice[56][9] = 'R';
}

void Mapp::ShowConsoleCursor(bool showFlag) {  //funzione per non fare vedere il cursore
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}