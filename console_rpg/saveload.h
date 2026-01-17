#pragma once

#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_

#include <fstream>
#include <string>
#include <filesystem>
#include <sstream>

class Player;
class Map;

class SaveLoad {
public:
	bool save(const Player&, const Map&, int);
	bool load(Player&, Map&, int);
	void erase(int slot);
};

#endif//_SAVELOAD_H_