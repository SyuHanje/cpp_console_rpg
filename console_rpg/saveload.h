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
private:
	//セーブフォルダ・ファイル生成
	const std::string saveDir = "save";
	std::string makePath(int) const;

public:

	//セーブ関数
	bool save(const Player&, const Map&, int);

	//ロード関数
	bool load(Player&, Map&, int);

	//セーブ削除関数
	void erase(int slot);
};

#endif//_SAVELOAD_H_