#pragma once

#ifndef _SAVELOAD_H_
#define _SAVELOAD_H_

#include <fstream>
#include <string>
#include "player.h"
#include "map.h"

class SaveLoad {
public:
	bool save(const Player&, const Map&, int);
	bool load(Player&, Map&, int);
};

#endif//_SAVELOAD_H_
