#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class Tile
{
public:
	Tile& operator = (const Tile &obj);
private:
	bool b_field[3][3] = { 0,0,0,
						 0,1,0,
						 0,0,0 };
	int count = 0;
	SDL_Rect TileRect;
	SDL_Rect TempRect;

	SDL_Surface *p_Grasstile;
	SDL_Surface *p_Pathtile;
	SDL_Surface *p_Blitter;
	SDL_Surface *p_Image;

public:
	void shiftClockWise();
	void setRect(int height, int width, int xpos, int ypos);

	SDL_Rect getRect();
	SDL_Surface* drawTile();
	void init();
	Tile();
	~Tile();
};

