#pragma once
#include <iostream>
#include <SDL.h>

using namespace std;

class W_Window
{
private:
	int height, width;
	SDL_Window* p_Window;
	SDL_Renderer* p_Renderer = NULL;
	SDL_Texture* p_Texture = NULL;
public:

	int getWindowHeight();
	int getWindowWidth();
	SDL_Texture* getTexture();
	SDL_Renderer* getRenderer();
	void render();
	void update();
	void destroy();
	void init(int height, int width);
	W_Window(int height, int width);
	~W_Window();
};