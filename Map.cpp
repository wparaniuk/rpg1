#include "Map.h"
#include "rapidxml_print.hpp"



Map::Map()
{
	//static_cast<float>(VideoMode::getDesktopMode().width);
	m_Scale = { 3,3 };
	m_Position = { 0,0 };
	walkableWalls = { 34,35,36,37,38,39,
		66,67,68,69,70,71,
		98,99,100,101,102,
		165,198,199,257,258,259,260,261,262,
		289,290,291,292,293,294,
		323,324,482,485 };
	walkableWallsLenght = ((sizeof walkableWalls) / (sizeof walkableWalls[0]));
	walkableFloors = { 69,70,71,
		130,131,132,133,134,135,
		162,163,164,
		194,195,196,197,
		231,294,
		354,355,356,357,358 };
	walkableFloorsLenght = ((sizeof walkableFloors) / (sizeof walkableFloors[0]));
	
	for (int i = 0, count = 1; i < 32; i++)
		for (int j = 0; j < 32; j++)
		{
			m_Spritesheet[count] = { j * 16, i * 16 };
			count++;
		}
		
	rapidcsv::Document map_1f("data/maps/map_1f.txt", rapidcsv::LabelParams(-1, -1));
	rapidcsv::Document map_1w("data/maps/map_1w.txt", rapidcsv::LabelParams(-1, -1));

	m_Size = { map_1f.GetColumnCount(), map_1f.GetRowCount() };
	
	for (int i = 0; i < m_Size.y; i++)
	{
		for (int j = 0; j < m_Size.x; j++)
		{
			m_BackgroundTexture[j][i][1].loadFromFile("data/images/dng_tileset.png",
				IntRect(m_Spritesheet[map_1f.GetCell<int>(j, i)].x, m_Spritesheet[map_1f.GetCell<int>(j, i)].y, 16, 16));
			m_BackgroundSprite[j][i][1].setTexture(m_BackgroundTexture[j][i][1]);
			m_BackgroundSprite[j][i][1].scale(m_Scale);

			m_BackgroundTexture[j][i][2].loadFromFile("data/images/dng_tileset.png",
				IntRect(m_Spritesheet[map_1w.GetCell<int>(j, i)].x, m_Spritesheet[map_1w.GetCell<int>(j, i)].y, 16, 16));
			m_BackgroundSprite[j][i][2].setTexture(m_BackgroundTexture[j][i][2]);
			m_BackgroundSprite[j][i][2].scale(m_Scale);
		}
	}

	
}

Vector2<size_t> Map::getMapSize()
{
	return m_Size;
}

int Map::getIdOfWallSprite(int x, int y)
{
	rapidcsv::Document map_1w("data/maps/map_1w.txt", rapidcsv::LabelParams(-1, -1));
	return map_1w.GetCell<int>(x, y);
}

int Map::getIdOfFloorSprite(int x, int y)
{
	rapidcsv::Document map_1f("data/maps/map_1f.txt", rapidcsv::LabelParams(-1, -1));
	if (x < 0 || y < 0 || x >= map_1f.GetColumnCount() || y >= map_1f.GetRowCount())
		return 0;
	else
		return map_1f.GetCell<int>(x, y);
}

int Map::getWalkableWall(int i)
{
	if (i == -1)
		return walkableWalls.size();
	else
		return walkableWalls[i];
}

int Map::getWalkableFloor(int i)
{
	if (i == -1)
		return walkableFloors.size();
	else
		return walkableFloors[i];
}

Sprite Map::getSprite(int x, int y, int level)
{
	return m_BackgroundSprite[x][y][level];
}

Vector2f Map::getCustomScale()
{
	return m_Scale;
}

void Map::update()
{
	for (int i = 0; i < m_Size.y; i++)
	{
		for (int j = 0; j < m_Size.x; j++)
		{
			m_BackgroundSprite[j][i][1].setPosition((j * 16 * m_Scale.x) + m_Position.x, i * 16 * m_Scale.y + m_Position.y);
			m_BackgroundSprite[j][i][2].setPosition(j * 16 * m_Scale.x + m_Position.x, i * 16 * m_Scale.y + m_Position.y);
			//if (map_1w.GetCell<int>(m_BackgroundSprite[j][i][2].getPosition().x / m_Scale.x,
			//	m_BackgroundSprite[j][i][2].getPosition().y / m_Scale.y) == 133)
			//{
				//m_BackgroundTexture[j][i][2].loadFromFile("data/images/dng_tileset.png",
				//	IntRect(m_Spritesheet[134].x, m_Spritesheet[134].y, 16, 16));
				//m_BackgroundSprite[j][i][2].setTexture();
			//}
		}
	}
	
}

