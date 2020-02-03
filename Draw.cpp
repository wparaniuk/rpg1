#include "stdafx.h"
#include "Engine.h"

void Engine::draw()
{
	// Rub out the last frame
	m_Window.clear(Color::Black);
	Font font;
	Text text;
	string displayText = "NULL";
	displayText = m_Bob.getText();
	if (!font.loadFromFile("data/fonts/martel.ttf"))
	{
		displayText = "Error";
	}

	for (int i = 0; i < m_Map.getMapSize().y; i++)
		for (int j = 0; j < m_Map.getMapSize().x; j++)
		{
			m_Window.draw(m_Map.getSprite(j, i, 1));
		}
	
	m_Window.draw(m_Bob.getSprite(2));

	for (int i = 0; i < m_Map.getMapSize().y; i++)
		for (int j = 0; j < m_Map.getMapSize().x; j++)
		{
			m_Window.draw(m_Map.getSprite(j, i, 2));
		}
	
	m_Window.draw(m_Bob.getSprite(1));

	text.setFont(font);
	text.setString(displayText);
	text.setCharacterSize(18);
	text.setFillColor(Color::White);
	if (displayText != "NULL")
	{
		m_Window.draw(text);
	}

	m_Window.display();
}