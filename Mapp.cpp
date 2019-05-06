#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "Mapp.h"
using namespace std;


Mapp::Mapp()
{
}


void Mapp::setMapp() {
	//setta la cornice
	for (int z = 0; z < x; z++) {
		for (int j = 0; j < y; j++) {
			matrice[z][j] = ' ';
		}
	}
	int i;
	matrice[0][0] = 201;
	matrice[19][0] = 200;
	matrice[0][100] = 187;
	matrice[19][100] = 188;
	for (i = 1; i < x - 1; i++)  matrice[i][0] = 186;
	for (i = 1; i < x - 1; i++)  matrice[i][y - 1] = 186;
	for (i = 1; i < y - 1; i++)  matrice[0][i] = 205;
	for (i = 1; i < y - 1; i++)  matrice[x - 1][i] = 205;
	for (i = 1; i < x - 1; i++)  matrice[i][78] = 186;
	for (i = 79; i < 100; i++) matrice[7][i] = 205;
	matrice[7][78] = 204;
	matrice[7][100] = 185;
	matrice[0][78] = 203;
	matrice[19][78] = 202;
}


void Mapp::setParametriGiocoUniverso(int fuel, int life) {
	int centinaia = (fuel / 100);
	int decine = ((fuel - (centinaia * 100)) / 10);
	int unità = (fuel - (centinaia * 100) - (decine * 10));
	matrice[1][79] = 'V';
	matrice[1][80] = 'I';
	matrice[1][81] = 'T';
	matrice[1][82] = 'A';
	matrice[1][83] = ':';
	matrice[1][84] = (char)life + 48;

	matrice[3][79] = 'C';
	matrice[3][80] = 'A';
	matrice[3][81] = 'R';
	matrice[3][82] = 'B';
	matrice[3][83] = 'U';
	matrice[3][84] = 'R';
	matrice[3][85] = 'A';
	matrice[3][86] = 'N';
	matrice[3][87] = 'T';
	matrice[3][88] = 'E';
	matrice[3][89] = ':';
	matrice[3][90] = (char)centinaia + 48;
	matrice[3][91] = (char)decine + 48;
	matrice[3][92] = (char)unità + 48;
	
	matrice[14][89] = '^';
	matrice[12][86] = 'F';
	matrice[12][87] = 'R';
	matrice[12][88] = 'E';
	matrice[12][89] = 'C';
	matrice[12][90] = 'C';
	matrice[12][91] = 'I';
	matrice[12][92] = 'A';
	matrice[13][88] = 'S';
	matrice[13][89] = 'U';

	matrice[16][89] = 'v';
	matrice[17][86] = 'F';
	matrice[17][87] = 'R';
	matrice[17][88] = 'E';
	matrice[17][89] = 'C';
	matrice[17][90] = 'C';
	matrice[17][91] = 'I';
	matrice[17][92] = 'A';
	matrice[18][88] = 'G';
	matrice[18][89] = 'I';
	matrice[18][90] = 'U';
	

	matrice[15][87] = '<';
	matrice[15][79] = 'F';
	matrice[15][80] = 'R';
	matrice[15][81] = 'E';
	matrice[15][82] = 'C';
	matrice[15][83] = 'C';
	matrice[15][84] = 'I';
	matrice[15][85] = 'A';
	matrice[16][81] = 'S';
	matrice[16][82] = 'X';

	matrice[15][91] = '>';
	matrice[15][93] = 'F';
	matrice[15][94] = 'R';
	matrice[15][95] = 'E';
	matrice[15][96] = 'C';
	matrice[15][97] = 'C';
	matrice[15][98] = 'I';
	matrice[15][99] = 'A';
	matrice[16][95] = 'D';
	matrice[16][96] = 'X';
}

void Mapp::setParametriGiocoPlanet(int fuel, int life) {
	setParametriGiocoUniverso(fuel, life);

	matrice[8][79] = 'q';
	matrice[8][80] = ':';
	matrice[8][81] = 'A';
	matrice[8][82] = 'T';
	matrice[8][83] = 'T';
	matrice[8][84] = 'I';
	matrice[8][85] = 'V';
	matrice[8][86] = 'A';
	matrice[8][87] = 'R';
	matrice[8][88] = 'E';
	matrice[8][89] = ' ';
	matrice[8][90] = 'R';
	matrice[8][91] = 'A';
	matrice[8][92] = 'G';
	matrice[8][93] = 'G';
	matrice[8][94] = 'I';
	matrice[8][95] = 'O';

	matrice[9][79] = 'w';
	matrice[9][80] = ':';
	matrice[9][81] = 'A';
	matrice[9][82] = 'N';
	matrice[9][83] = 'N';
	matrice[9][84] = 'U';
	matrice[9][85] = 'L';
	matrice[9][86] = 'L';
	matrice[9][87] = 'A';
	matrice[9][88] = 'R';
	matrice[9][89] = 'E';
	matrice[9][90] = ' ';
	matrice[9][91] = 'R';
	matrice[9][92] = 'A';
	matrice[9][93] = 'G';
	matrice[9][94] = 'G';
	matrice[9][95] = 'I';
	matrice[9][96] = 'O';

	matrice[10][79] = 's';
	matrice[10][80] = 'p';
	matrice[10][81] = 'a';
	matrice[10][82] = 'c';
	matrice[10][83] = 'e';
	matrice[10][84] = ':';
	matrice[10][85] = 'S';
	matrice[10][86] = 'P';
	matrice[10][87] = 'A';
	matrice[10][88] = 'R'; 
	matrice[10][89] = 'A';
	matrice[10][90] = 'R';
	matrice[10][91] = 'E';
}

void Mapp::setInitiallyParameters(int fuel, int life) {
	int centinaia = (fuel / 100);
	int decine = ((fuel - (centinaia * 100)) / 10);
	int unità = (fuel - (centinaia * 100) - (decine * 10));
	matrice[3][90] = (char)centinaia + 48;
	matrice[3][91] = (char)decine + 48;
	matrice[3][92] = (char)unità + 48;
	matrice[1][84] = (char)life + 48;
}

//stampa la mappa
void Mapp::printMapp() {
	system("cls");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (((matrice[i][j] == 'O')&& (j<=78) ) || (((i >= 10) && (i <= 16)) && ((j>=1) && (j<= 77)))) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			if (matrice[i][j] == '@') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
			cout << matrice[i][j];
		}
		cout << "\n";
	}
}

void Mapp::printInitialMapp() {
	system("cls");
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cout << matrice[i][j];
		}
		cout << "\n";
	}
}


void Mapp::setInitialMapp() {
	//setta la cornice
	for (int z = 0; z < x; z++) {
		for (int j = 0; j < y; j++) {
			matrice[z][j] = ' ';
		}
	}
	int i;
	matrice[0][0] = 201;
	matrice[19][0] = 200;
	matrice[0][100] = 187;
	matrice[19][100] = 188;
	for (i = 1; i < x - 1; i++)  matrice[i][0] = 186;
	for (i = 1; i < x - 1; i++)  matrice[i][y - 1] = 186;
	for (i = 1; i < y - 1; i++)  matrice[0][i] = 205;
	for (i = 1; i < y - 1; i++)  matrice[x - 1][i] = 205;


	matrice[9][48] = 'N';
	matrice[9][49] = 'O';
	matrice[9][50] = ' ';
	matrice[9][51] = 'G';
	matrice[9][52] = 'R';
	matrice[9][53] = 'A';
	matrice[9][54] = 'V';
	matrice[9][55] = 'I';
	matrice[9][56] = 'T';
	matrice[9][57] = 'A';
	matrice[9][58] = 'R';

	matrice[10][44] = 'P';
	matrice[10][45] = 'r';
	matrice[10][46] = 'e';
	matrice[10][47] = 'm';
	matrice[10][48] = 'e';
	matrice[10][49] = 'r';
	matrice[10][50] = 'e';
	matrice[10][51] = ' ';
	matrice[10][52] = 't';
	matrice[10][53] = 'a';
	matrice[10][54] = 's';
	matrice[10][55] = 't';
	matrice[10][56] = 'o';
	matrice[10][57] = ' ';
	matrice[10][58] = 'i';
	matrice[10][59] = 'n';
	matrice[10][60] = 'v';
	matrice[10][61] = 'i';
	matrice[10][62] = 'o';
}

void Mapp::setFinalMapp() {
	//setta la cornice
	for (int z = 0; z < x; z++) {
		for (int j = 0; j < y; j++) {
			matrice[z][j] = ' ';
		}
	}
	int i;
	matrice[0][0] = 201;
	matrice[19][0] = 200;
	matrice[0][100] = 187;
	matrice[19][100] = 188;
	for (i = 1; i < x - 1; i++)  matrice[i][0] = 186;
	for (i = 1; i < x - 1; i++)  matrice[i][y - 1] = 186;
	for (i = 1; i < y - 1; i++)  matrice[0][i] = 205;
	for (i = 1; i < y - 1; i++)  matrice[x - 1][i] = 205;

	matrice[9][48] = 'G';
	matrice[9][49] = 'A';
	matrice[9][50] = 'M';
	matrice[9][51] = 'E';
	matrice[9][52] = ' ';
	matrice[9][53] = '0';
	matrice[9][54] = 'V';
	matrice[9][55] = 'E';
	matrice[9][56] = 'R';
}