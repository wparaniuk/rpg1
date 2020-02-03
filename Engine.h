#pragma once
#include <SFML/Graphics.hpp>
#include "Bob.h"
#include "Map.h"

using namespace sf;
using namespace rapidxml;

class Engine
{
private:

	// A regular RenderWindow
	RenderWindow m_Window;
	Event event;
	// An instance of Bob
	Bob m_Bob;
	Map m_Map;

	// Private functions for internal use only
	void input();
	void update();
	void draw();

public:
	// The Engine constructor
	Engine();

	// start will call all the private functions
	void start();

};