#pragma once
#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "character.h"
#include "random.h"

class Enemy : public Character {

    //“GƒXƒe[ƒ^ƒXİ’è
public:
    Enemy() : Character("“G", 15, 100, 0, 100) {}

    //“Gí—Ş
    Enemy(int);

    //í“¬ˆ—(“G)
    void dmg(int) override;

    int applyRandomHp(const StatusRate&);
    int applyRandomAtk(const StatusRate&);
    int applyRandomDef(const StatusRate&);
};

#endif //_ENEMY_H_