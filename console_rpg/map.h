#pragma once
#ifndef _MAP_H_
#define _MAP_H_

#include<vector>
#include "player.h"
#include "game.h"
#include "skill.h"
#include "random.h"
#include "saveload.h"

class Map {
public:
	Game game;
	Player player;
	SaveLoad saveLoad;
	
	//マップ遷移コントロール
	void map_main();

	//マップ表示関連
	void map_display();

	//マップ移動選択
	void move();

	//マップ移動処理
	void applyMove();

	//イベントコントロール
	void event_display();

	//マップセーブ・ロード用の取得・代入
	void setPosition(int px, int py);
	int getX() const;
	int getY() const;
	int(&getMap())[5][12];
	const int(&getMap() const)[5][12];

	void setMapCell(int i, int j, int value);

private:

	//マップ構成&ベント選択用変数
	int event = 0;
	int x = 3;
	int y = 1;
	int max_x = 5;
	int max_y = 12;
	int map[5][12] = {
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{ -1, 0, -1, 3, 0, 0, 0, 0, 0, 0, 4, -1},
		{ -1, 3, 0, 0, 2, 0, 0, 0, 0, 0, 3, -1},
		{ -1, 1, 3, 3, 0, 0, 0, 0, 0, 0, 0,- 1},
		{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
	};
};

#endif//_MAP_H_
