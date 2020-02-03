#include "Bob.h"

Bob::Bob()
{
	m_Scale = { 3,3 };
	// How fast does Bob move?
	m_Speed = 400;
	rectSourceSprite1 = { 128, 160, 16, 16 };
	rectSourceSprite2 = { 128, 176, 16, 16 };
	// Associate a texture with the sprite
	m_Texture1.loadFromFile("data/images/dng_tileset.png", rectSourceSprite1);
	m_Texture2.loadFromFile("data/images/dng_tileset.png", rectSourceSprite2);
	m_Sprite1.setTexture(m_Texture1);
	m_Sprite2.setTexture(m_Texture2);
	m_Position = { 8 * 16 * m_Scale.x, 2 * 16 * m_Scale.x };
	m_Sprite1.scale(m_Scale);
	m_Sprite2.scale(m_Scale);
	displayText = "NULL";
}

Sprite Bob::getSprite(int i)
{
	if (i == 1)
		return m_Sprite1;
	else if (i == 2)
		return m_Sprite2;
}

string Bob::moveLeft(string move)
{
	if ("LEFT" == move)
	{
		m_Sprite1.setOrigin(m_Sprite1.getLocalBounds().width, 0);
		m_Sprite1.setScale(-1 * m_Scale.x, 1 * m_Scale.y);
		m_Sprite2.setOrigin(m_Sprite2.getLocalBounds().width, 0);
		m_Sprite2.setScale(-1 * m_Scale.x, 1 * m_Scale.y);
		return m_Position_Direction = move;
	}
	else if ("WALL" == move)
	{
		displayText = "You cannot move in this direction.";
		return m_Position_Direction = "STOP";
	}
	else
		return m_Position_Direction = "STOP";
}

string Bob::moveRight(string move)
{
	if ("RIGHT" == move)
	{
		m_Sprite1.setOrigin(0, 0);
		m_Sprite1.setScale(1 * m_Scale.x, 1 * m_Scale.y);
		m_Sprite2.setOrigin(0, 0);
		m_Sprite2.setScale(1 * m_Scale.x, 1 * m_Scale.y);
		return m_Position_Direction = move;
	}
	else if ("WALL" == move)
	{
		displayText = "You cannot move in this direction.";
		return m_Position_Direction = "STOP";
	}
	else
		return m_Position_Direction = "STOP";
}

string Bob::moveUp(string move)
{
	if ("UP" == move)
	{
		return m_Position_Direction = move;
	}
	else if ("WALL" == move)
	{
		displayText = "You cannot move in this direction.";
		return m_Position_Direction = "STOP";
	}
	else
		return m_Position_Direction = "STOP";
}

string Bob::moveDown(string move)
{
	if ("DOWN" == move)
	{
		return m_Position_Direction = move;
	}
	else if ("WALL" == move)
	{
		displayText = "You cannot move in this direction.";
		return m_Position_Direction = "STOP";
	}
	else
		return m_Position_Direction = "STOP";
}

Vector2f Bob::getCustomScale()
{
	return m_Scale;
}

string Bob::getText()
{
	return displayText;
}

void Bob::update()
{
	if (m_Position_Direction == "LEFT")
		rectSourceSprite2.left = walkLeft();
	else if (m_Position_Direction == "RIGHT")
		rectSourceSprite2.left = walkRight();
	else if (m_Position_Direction == "UP")
		rectSourceSprite2.left = walkUp();
	else if (m_Position_Direction == "DOWN")
		rectSourceSprite2.left = walkDown();

	m_Texture1.loadFromFile("data/images/dng_tileset.png", IntRect(rectSourceSprite2.left, 160, 16, 16));
	m_Texture2.loadFromFile("data/images/dng_tileset.png", IntRect(rectSourceSprite2.left, 176, 16, 16));
	m_Sprite1.setTexture(m_Texture1);
	m_Sprite2.setTexture(m_Texture2);
	m_Sprite1.setPosition(m_Position.x, m_Position.y - 16 * m_Scale.y);
	m_Sprite2.setPosition(m_Position);
}