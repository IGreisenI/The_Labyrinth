#include "Tile.h"

Tile::Tile() {
	init();
}

//initialises the tile(assings random bools to changing tiles, loads the textures for different tiles) 
void Tile::init() {
	while (count < 2) {
		count = 0;
		b_field[0][1] = rand() / 10000;
		b_field[1][0] = rand() / 10000;
		b_field[1][2] = rand() / 10000;
		b_field[2][1] = rand() / 10000;

		if (b_field[0][1] == 1) {
			count++;
		}
		if (b_field[1][0] == 1) {
			count++;
		}
		if (b_field[1][2] == 1) {
			count++;
		}
		if (b_field[2][1] == 1) {
			count++;
		}
	}
	p_Pathtile = IMG_Load("res/pathtile.png");
	if (p_Pathtile == NULL) {
		cout << "Pathtile couldn't be loaded" << endl;
	}
	p_Grasstile = IMG_Load("res/grasstile.png");
	if (p_Grasstile == NULL) {
		cout << "Grasstile couldn't be loaded" << endl;
	}
}

Tile::~Tile()
{
	p_Grasstile = NULL;
	p_Pathtile = NULL;
	p_Blitter = NULL;
	p_Image = NULL;
}

//rotates the tile clockwise by changing the values of changing tiles
void Tile::shiftClockWise() {
	bool temp = b_field[1][0];
	b_field[1][0] = b_field[0][1];
	b_field[0][1] = b_field[1][2];
	b_field[1][2] = b_field[2][1];
	b_field[2][1] = temp;
}

//adjusts the SDL_Rect for the tile
void Tile::setRect(int height, int width, int xpos, int ypos) {
	TileRect.h = height;
	TileRect.w = width;
	TileRect.x = xpos;
	TileRect.y = ypos;
}

//loads the blitter and blits the whole tile on it with coorespoding textures
SDL_Surface* Tile::drawTile() {
	p_Blitter = IMG_Load("res/blitter.png");
	if (p_Blitter == NULL) {
		cout << "Blitter couldn't be loaded" << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			TempRect.x = 20*i;
			TempRect.y = 20*j;
			TempRect.h = TempRect.w = 0;


			if (!b_field[i][j]) {
				p_Image = SDL_ConvertSurface(p_Grasstile, p_Grasstile->format, 0);
			}
			else if(b_field[i][j]) {
				p_Image = SDL_ConvertSurface(p_Pathtile, p_Pathtile->format, 0);
			}

			SDL_BlitSurface(p_Image, NULL, p_Blitter, &TempRect);
			SDL_FreeSurface(p_Image);
		}
	}
	return p_Blitter;
}

//gets the SDL_Rect of the whole tile
SDL_Rect Tile::getRect() {
	return TileRect;
}

//overloads the operator
Tile& Tile::operator = (const Tile &obj) {
	this->b_field[0][1] = obj.b_field[0][1];
	this->b_field[1][0] = obj.b_field[1][0];
	this->b_field[2][1] = obj.b_field[2][1];
	this->b_field[1][2] = obj.b_field[1][2];
	return *this;
}