#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Bob
{
	// All the private variables can only be accessed internally
private:

	// Where is Bob
	Vector2f m_Position;
	Vector2f m_Scale;
	// Of course we will need a sprite
	
	Vector2f resolution;
	// And a texture
	// Bob has been working out and he is now a bit more muscular than before
	Texture m_Texture;
	Texture m_Texture1;
	Texture m_Texture2;
	Sprite m_Sprite1;
	Sprite m_Sprite2;
	// Bob's speed in pixels per second
	float m_Speed;
	IntRect rectSourceSprite1;
	IntRect rectSourceSprite2;
	string displayText;
	//Bob direction -1=left, 1=right, 0=up/down
	string m_Position_Direction; 
	int distance;
	int walkUp();
	int walkDown();
	int walkLeft();
	int walkRight();
public:

	// We will set Bob up in the constructor
	Bob();

	// Send a copy of the sprite to main
	Sprite getSprite(int i);

	Vector2f getCustomScale();

	// Move Bob in a specific direction
	string moveLeft(string move);
	string moveRight(string move);
	string moveUp(string move);
	string moveDown(string move);

	string getText();

	// We will call this function once every frame
	void update();

};