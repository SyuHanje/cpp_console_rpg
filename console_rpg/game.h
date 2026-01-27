#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "player.h"
#include "enemy.h"
#include "action.h"
#include "random.h"
#include "battle.h"
#include "saveload.h"
#include "map.h"

class Game {

public:
    Game() {}


    //マップ遷移コントロール
    void run(Map& map, Player& player, SaveLoad& saveLoad);

    //ランダムイベント管理
    int handleMapEvent(int cell, Player& player, SaveLoad& saveLoad);

    //エンカウントする敵の選別
    int start(Player& player);
    void boss_start(Player& player);
};

#endif //_GAME_H_
