#pragma once

#ifndef _BATTLE_H_
#define _BATTLE_H_

#include "action.h"
#include "player.h"
#include "enemy.h"

class Battle {
private:
    //行動コマンド用
    Action act;

public:
    //戦闘関数
    void run(Player& player, Enemy& enemy);
};

#endif//_BATTLE_H_
