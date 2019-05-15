#pragma once

typedef class Bunker2* ptr_Bunker2;
struct listaBunker2 {
	ptr_Bunker2 b2;
	listaBunker2* next;
	listaBunker2* prev;
};
typedef listaBunker2* ptr_listaBunker2;


class Bunker2 {
protected:
	int xBunker2;
	int yBunker2;
	int lifeBunker2;
public:
	Bunker2(int x, int y, int life);
	int coordinateBunker2(bool b);
};
typedef class Bunker2* ptr_Bunker2;
