#include "E_Event.h"



E_Event::E_Event(Map* p_map)
{
	init(p_map);
}

//initialises the class
void E_Event::init(Map* p_map) {
	this->p_map = p_map;
}

E_Event::~E_Event()
{
}

//processes events
void E_Event::processEvents(SDL_Event _Event) {
	
	switch (_Event.type) {
	//checks if the user clicked on the x of the window
	case SDL_QUIT:
		exit(1);
		break;
	//checks keys that have been released
	case SDL_KEYUP:
		//checks the r key
		if (_Event.key.keysym.sym == SDLK_r) {
			cout << "R key pressed" << endl;
			SDL_GetMouseState(&xKor, &yKor);
			p_map->rotateTile(xKor, yKor);
		}
	//checks if the mouse button has been released
	case SDL_MOUSEBUTTONUP:
		//checks the left click
		if (_Event.button.button == SDL_BUTTON_LEFT) {
			cout << "Left click pressed" << endl;
			SDL_GetMouseState(&xKor, &yKor);
			p_map->shiftMap(xKor, yKor);
		}

	}
}