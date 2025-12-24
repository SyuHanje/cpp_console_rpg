#pragma once
#include "player.h"
#include "enemy.h"
#include "action.h"
#include "random.h"

#ifndef _GAME_H_
#define _GAME_H_

class Game {

private:

    //ターン経過＆コマンド入力
    Action act;

public:
    Game() {}

    //エンカウントする敵の選別
    int start(Player& player);
    void boss_start(Player& player);

private:

    //戦闘用関数
    void battle(Player& player, Enemy& enemy);
};

#endif //_GAME_H_
