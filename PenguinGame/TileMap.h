#pragma once
#ifndef TILEMAP_H
#define TILEMAP_H
#include "GameObject.h"
#include "TileSet.h"
#include <string>
#include <vector>
#include <fstream>


class TileMap : public Component
{
public:
	TileMap(GameObject& associated, std::string file, TileSet* tileSet);
	~TileMap();

	void Load(std::string file);

	void SetTileSet(TileSet* tileSet);

	int& At(int x, int y, int z = 0);

	void Render();

	void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);

	int GetWidth();
	int GetHeight();
	int GetDepth();

	bool Is(std::string type);
	void Update(float dt);

private:
	int CoordToIndex(int x, int y, int z);
	
	std::vector<int> tileMatrix;
	TileSet* tileSet;
	int mapWidth;
	int mapHeight;
	int mapDepth;
};


#endif // TILEMAP_H
