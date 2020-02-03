#include "stdafx.h"
#include "Engine.h"

using namespace sf;

void Engine::update()
{
	m_Bob.update();
	m_Map.update();
}