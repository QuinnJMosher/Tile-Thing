#include "World.h" 

World::World() {
	worldTiles = vector<vector<TileType>>();
	tileInfo = vector<TileData>();
}

World::~World() {
	worldTiles.~vector();
	tileInfo.~vector();
}

void World::ReadyTiles() {
	TileData newInfo;

	newInfo.ID = CreateSprite("rockTileTexture.png", 10, 10, false);
	newInfo.type = TileType::ROCK;
	tileInfo.emplace_back(newInfo);

	newInfo.ID = CreateSprite("grassTileTexture.png", 10, 10, false);
	newInfo.type = TileType::GRASS;
	tileInfo.emplace_back(newInfo);

	newInfo.ID = CreateSprite("waterTileTexture.png", 10, 10, false);
	newInfo.type = TileType::WATER;
	tileInfo.emplace_back(newInfo);
}

//will read from a file to create the tile types, right now it just goes to preset values
void World::ReadyTilesFromFile(string in_filename) {
	ReadyTiles();
}

void World::TestCreate() {
	for (int i = 0; i < 3; i++) {
		worldTiles.emplace_back(vector<TileType>());
	}

	worldTiles.at(0).emplace_back(TileType::GRASS);
	worldTiles.at(0).emplace_back(TileType::GRASS);
	worldTiles.at(0).emplace_back(TileType::GRASS);

	worldTiles.at(1).emplace_back(TileType::GRASS);
	worldTiles.at(1).emplace_back(TileType::WATER);
	worldTiles.at(1).emplace_back(TileType::ROCK);

	worldTiles.at(2).emplace_back(TileType::ROCK);
	worldTiles.at(2).emplace_back(TileType::ROCK);
	worldTiles.at(2).emplace_back(TileType::ROCK);

}

//will read from file, right now it just calls the test create meathod
//will require that the grid is rectangular (will add an "empty" tileType later)
void World::CreateFromFile(string in_filename) {
	TestCreate();
	for (int i = 1; i < worldTiles.size(); i++) {
		assert(worldTiles.at(i).size() == worldTiles.at(i - 1).size());
	}
}

void World::SetTile(int in_x, int in_y, TileType in_type) {
	if (in_x < worldTiles.size()) {
		if (in_y < worldTiles[in_x].size()) {
			worldTiles[in_x][in_y] = in_type;
		}
	}
}

TileType World::GetTile(int in_x, int in_y) {
	if (in_x < worldTiles.size()) {
		if (in_y < worldTiles[in_x].size()) {
			return worldTiles[in_x][in_y];
		}
	}
}

void World::Draw() {
	for (int i = 0; i < worldTiles.size(); i++) {
		for (int j = 0; j < worldTiles[i].size(); j++) {
			//add positioning/movesprite
			DrawSprite(tileInfo[worldTiles[i][j]].ID);//will have to change tileInfo a bit so this is acurate even when the tiles are out of order in tileinfo
		}
	}
}

void World::WriteToConsole() {
	cout << "World Info\n";
	cout << "Current Tile Info\n";
	for (int i = 0; i < tileInfo.size(); i++) {
		cout << "Entry: " << i << endl;

		switch (tileInfo[i].type) {
		case TileType::GRASS:
			cout << "Type: Grass\n";
			break;
		case TileType::ROCK:
			cout << "Type: Rock\n";
			break;
		case TileType::WATER:
			cout << "Type: Water\n";
			break;
		default:
			cout << "Type: Invalid\n";
			break;
		}

		cout << "TextureID: " << tileInfo[i].ID << endl;
	}

	cout << "World Tile IDs\n";
	for (int i = 0; i < worldTiles.size(); i++) {
		for (int j = 0; j < worldTiles[i].size(); j++) {
			cout << worldTiles[i][j] << " ";
		}
		cout << endl;
	}
}