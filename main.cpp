#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "W_Window.h"
#include "E_Event.h"

using namespace std;

int main(int argc, char* argv[]) {

	IMG_Init(IMG_INIT_PNG);

	//initing Window
	W_Window *p_Window = new W_Window(480, 480);
	if (p_Window == NULL) {
		cout << "Window couldn't be created" << SDL_GetError() << endl;
	}
	//initing Map
	Map Map(p_Window);
	if (&Map == NULL) {
		cout << "Map couldn't be initialised" << SDL_GetError() << endl;
	}
	//initing Event
	E_Event Event(&Map);
	if (&Event == NULL) {
		cout << "E_Event object couldn't be initialised" << SDL_GetError() << endl;
	}

	//game loop
	while (true)
	{
		SDL_Event _Event;
		if (&_Event == NULL) {
			cout << "SDL_Event couldn't be initialised" << SDL_GetError() << endl;
		}
		while (SDL_PollEvent(&_Event) != 0)
		{
			Event.processEvents(_Event);
		}
		
		Map.updateMap();
		p_Window->update();
		p_Window->render();

	}

	p_Window->destroy();
	IMG_Quit();
	SDL_Quit();
	
	return 0;
}
