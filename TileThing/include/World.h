#ifndef _World_h_
#define _World_h_
#include "AIE.h"
#include <vector>
#include <string>
#include <assert.h>
#include <iostream>

using namespace std;
typedef unsigned int AIE_TextureID;

enum TileType {
	ROCK,
	GRASS,
	WATER
};

struct TileData {
	TileType type;
	AIE_TextureID ID;
};

class World {
public:
	World();
	~World();

	void ReadyTiles();
	void ReadyTilesFromFile(string in_filename);

	void TestCreate();
	void CreateFromFile(string in_filename);

	void SetTile(int in_x, int in_y, TileType in_type);
	TileType GetTile(int in_x, int in_y);

	void Draw();
	void WriteToConsole();

private:
	vector<vector<TileType>>worldTiles;//2d vector
	vector<TileData>tileInfo;

};

#endif