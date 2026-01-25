#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "player.h"
#include "enemy.h"
#include "action.h"
#include "random.h"
#include "battle.h"

class Game {

public:
    Game() {}

    //エンカウントする敵の選別
    int start(Player& player);
    void boss_start(Player& player);
};

#endif //_GAME_H_
