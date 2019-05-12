#pragma once


typedef class Bunker* ptr_Bunker;

struct listaBunker {
	ptr_Bunker b1;
	listaBunker* next;
	listaBunker* prev;
};
typedef listaBunker* ptr_listaBunker;


class Bunker{
protected:
	int xBunker;
	int yBunker;
	int lifeBunker;
public:
	Bunker(int x, int y, int life);
	int coordinateBunker(bool b);


};
typedef class Bunker* ptr_Bunker;


