#pragma once
#include <SFML/Graphics.hpp>
#include "stdafx.h"
#include "RapidSCV.h"

using namespace sf;

class Map
{
private:
	Vector2<size_t> m_Size;
	vector<int> walkableWalls;
	int walkableWallsLenght;
	vector<int> walkableFloors;
	int walkableFloorsLenght;
	Sprite m_BackgroundSprite[12][12][2];
	Texture m_BackgroundTexture[12][12][2];
	Vector2i m_Spritesheet[1025];
	Vector2f m_Position;
	Vector2f m_Scale;
	rapidcsv::Document map_1f;
	rapidcsv::Document map_1w;
	Vector2f resolution;
public:
	Map();

	Sprite getSprite(int x, int y, int level);

	Vector2<size_t> getMapSize();

	int getIdOfWallSprite(int x, int y);

	int getIdOfFloorSprite(int x, int y);

	int getWalkableWall(int i = -1);

	int getWalkableFloor(int i = -1);

	Vector2f getCustomScale();

	void update();
};

