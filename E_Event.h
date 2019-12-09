#pragma once
#include <iostream>
#include "SDL.h"
#include "Map.h"

using namespace std;

class E_Event
{
private:
	int xKor, yKor;
	Map* p_map;
	SDL_Event* _Events;
public:
	void checkEvents();
	void processEvents(SDL_Event _Event);

	void init(Map* p_map);
	E_Event(Map* p_map);
	~E_Event();
};

