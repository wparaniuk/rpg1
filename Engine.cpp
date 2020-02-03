#include "stdafx.h"
#include "Engine.h"

Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	//resolution.x = VideoMode::getDesktopMode().width;
	//resolution.y = VideoMode::getDesktopMode().height;
	resolution.x = m_Map.getMapSize().x * 16 * m_Map.getCustomScale().x;
	resolution.y = m_Map.getMapSize().y * 16 * m_Map.getCustomScale().y;
	m_Window.create(VideoMode(resolution.x, resolution.y), "Simple Game Engine", Style::Close);
	//m_Window.setKeyRepeatEnabled(false);
}

void Engine::start()
{
	// Timing
	Clock clock;

	while (m_Window.isOpen())
	{
		while (m_Window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				m_Window.close();
			// Restart the clock and save the elapsed time into dt
			Time dt = clock.restart();

			// Make a fraction from the delta time
			float dtAsSeconds = dt.asSeconds();
			float dtAsMiliseconds = dt.asMilliseconds();

			input();
			for (int i = 1; i < 5; i++)
			{
				update();
				draw();
			}
		}
	}
}