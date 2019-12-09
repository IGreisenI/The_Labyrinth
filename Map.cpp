#include "Map.h"

Map::Map(W_Window *p_window)
{
	init(p_window);
}

void Map::init(W_Window *p_window) {
	this->height = p_window->getWindowHeight();
	this->width = p_window->getWindowWidth();
	this->p_Texture = p_window->getTexture();
	this->p_Renderer = p_window->getRenderer();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			TileMap[i][j].setRect(height / 8, width / 8, i*(height / 8), j*(width / 8));
		}
	}
}

Map::~Map()
{
	SDL_DestroyTexture(p_Texture);
	SDL_DestroyRenderer(p_Renderer);
}

//takes the coordinates and finds the tile clicked, checks if it's the border one and moves the others
void Map::shiftMap(int xKor, int yKor) {
	int col = xKor / (height / 8);
	int row = yKor / (width / 8);

	Tile TempTile = TileMap[col][row];

	if ((col == 0 && row == 0) ||(col == 0 && row == 7)||(col == 7 && row == 0)||(col == 7 && row == 7)) {
		return;
	}
	
	if (col == 0) {
		for (int i = 0; i < 7; i++) {
			TileMap[i][row] = TileMap[i + 1][row];
		}
		TileMap[7][row] = TempTile;
		return;
	}

	if (col == 7) {
		for (int i = 7; i > 0; i--) {
			TileMap[i][row] = TileMap[i - 1][row];
		}
		TileMap[0][row] = TempTile;
		return;
	}

	if (row == 0) {
		for (int i = 0; i < 7; i++) {
			TileMap[col][i] = TileMap[col][i + 1];
		}
		TileMap[col][7] = TempTile;
		return;
	}

	if (row == 7) {
		for (int i = 7; i > 0; i--) {
			TileMap[col][i] = TileMap[col][i - 1];
		}
		TileMap[col][0] = TempTile;
		return;
	}

}

//takes the coordinates and calculates which tile was clicked and passes it in a fuction for rotating 
void Map::rotateTile(int xkor, int ykor) {
	int xid = xkor / (width / 8);
	int yid = ykor / (height / 8);

	TileMap[xid][yid].shiftClockWise();
}


//updates the renderer with textures of each tile
void Map::updateMap() {
	SDL_RenderClear(p_Renderer);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			SDL_Surface *tempSurface = TileMap[i][j].drawTile();
			p_Texture = SDL_CreateTextureFromSurface(p_Renderer, tempSurface);
			SDL_RenderCopy(p_Renderer, p_Texture, NULL, &TileMap[i][j].getRect());
			SDL_DestroyTexture(p_Texture);
			SDL_FreeSurface(tempSurface);
		}
	}
}