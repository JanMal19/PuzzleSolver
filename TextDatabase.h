#pragma once

#include "Player.h"
#include <vector>

using namespace std;

public class TextDatabase {
public:
	static const string playerDatabaseName;
	static bool SavePlayerToDatabase(Player p);
	static bool DataBaseExist(const std::string& path);
	static std::vector<std::string> GetPlayers();
};