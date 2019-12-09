#include "W_Window.h"



W_Window::W_Window(int height, int width)
{	
	init(height, width);
}

void W_Window::init(int height, int width) {
	this->height = height;
	this->width = width;

	SDL_Init(SDL_INIT_EVERYTHING);

	p_Window = SDL_CreateWindow("Labyrinth", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	if (p_Window == NULL) {
		cout << "Could not create window: " << SDL_GetError() << endl;
		exit(1);
	}
	p_Renderer = SDL_CreateRenderer(p_Window, -1, SDL_RENDERER_ACCELERATED);
	if (p_Renderer == NULL) {
		cout << "Renderer couldn't be initialised" << SDL_GetError() << endl;
	}
	p_Texture = SDL_CreateTexture(p_Renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, height, width);
	if (p_Texture == NULL) {
		cout << "Texture couldn't be created" << SDL_GetError() << endl;
	}
}

W_Window::~W_Window()
{
}

void W_Window::update() {
}

void W_Window::render() {
	SDL_RenderPresent(p_Renderer);
	SDL_RenderClear(p_Renderer);
}

void W_Window::destroy() {
	SDL_DestroyTexture(p_Texture);
	SDL_DestroyRenderer(p_Renderer);
	SDL_DestroyWindow(p_Window);
}

int W_Window::getWindowHeight() {
	return height;
}

int W_Window::getWindowWidth() {
	return width;
}

SDL_Texture* W_Window::getTexture() {
	return p_Texture;
}

SDL_Renderer* W_Window::getRenderer() {
	return p_Renderer;
}