#include "stdafx.h"
#include "Engine.h"

void Engine::input()
{
	Vector2f scale = m_Map.getCustomScale();
	Vector2f m_Bob_Position = m_Bob.getSprite(2).getPosition();

	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}

	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::A))
	{
		for (int i = 0; i < m_Map.getWalkableFloor(); i++)
		{
			if (m_Map.getIdOfFloorSprite((m_Bob_Position.x / scale.x - 16) / 16, m_Bob_Position.y / scale.y / 16)
				== m_Map.getWalkableFloor(i))
			{
				m_Bob.moveLeft("LEFT");
				break;
			}
			else if (m_Map.getIdOfFloorSprite(m_Bob_Position.x / scale.x / 16, (m_Bob_Position.y / scale.y - 16) / 16)
				== 0)
				m_Bob.moveLeft("WALL");
		}
	}

	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::D))
	{
		for (int i = 0; i < m_Map.getWalkableFloor(); i++)
		{
			if (m_Map.getIdOfFloorSprite((m_Bob_Position.x / scale.x + 16) / 16, m_Bob_Position.y / scale.y / 16)
				== m_Map.getWalkableFloor(i))
			{
				m_Bob.moveRight("RIGHT");
				break;
			}
			else if (m_Map.getIdOfFloorSprite(m_Bob_Position.x / scale.x / 16, (m_Bob_Position.y / scale.y - 16) / 16)
				== 0)
				m_Bob.moveRight("WALL");
		}
	}

	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::W))
	{
		for (int i = 0; i < m_Map.getWalkableFloor(); i++)
		{
			if (m_Map.getIdOfFloorSprite(m_Bob_Position.x / scale.x / 16, (m_Bob_Position.y / scale.y - 16) / 16)
				== m_Map.getWalkableFloor(i))
			{
				m_Bob.moveUp("UP");
				break;
			}
			else if (m_Map.getIdOfFloorSprite(m_Bob_Position.x / scale.x / 16, (m_Bob_Position.y / scale.y - 16) / 16)
				== 0)
				m_Bob.moveUp("WALL");
		}
	}

	if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::S))
	{
		for (int i = 0; i < m_Map.getWalkableFloor(); i++)
		{
			if (m_Map.getIdOfFloorSprite(m_Bob_Position.x / scale.x / 16, (m_Bob_Position.y / scale.y + 16) / 16)
				== m_Map.getWalkableFloor(i))
			{
				m_Bob.moveDown("DOWN");
				break;
			}
			else if (m_Map.getIdOfFloorSprite(m_Bob_Position.x / scale.x / 16, (m_Bob_Position.y / scale.y - 16) / 16)
				== 0)
				m_Bob.moveDown("WALL");
		}
	}
}