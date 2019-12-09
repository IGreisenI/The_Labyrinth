#pragma once
#include <iostream>
#include "Tile.h"
#include "W_Window.h"

using namespace std;

class Map
{
private:
	int height, width;
	Tile TileMap[8][8];
	SDL_Texture *p_Texture = NULL;
	SDL_Renderer *p_Renderer = NULL;

public:
	void shiftMap(int xkor, int ykor);
	void rotateTile(int xkor, int ykor);
	void updateMap();
	void init(W_Window *p_window);
	Map(W_Window *window);
	~Map();
};

