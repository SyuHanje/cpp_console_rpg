#include "skill.h"
#include "player.h"
#include <iostream>

using namespace std;

//ランダムマス経由のスキル抽選
Skill* createNormalSkill(int raffle) {
    switch (raffle) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return new LowHpAttackUp();
    }
    return nullptr;
}

//Eマス経由のスキル抽選
Skill* createSpecialSkill(int raffle) {
    switch (raffle) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        return new SuperLowHpAttackUp();
    }
    return nullptr;
}


//以下、スキル定義関数
void LowHpAttackUp::apply(Player& player) {

    //スキルが発動しているのかの確認
    if (player.lowHpTriggered) {
        return;
    }

    //発動条件:HP80%以下のターン開始時(戦闘中一回のみ)　　効果：その戦闘中、ATK+30%(レベルアップするごとに、追加で+30%)
    if (player.getHp() <= player.getMaxHp() * 0.8) {
        int base = static_cast<int>(player.getAtk() * 0.3);
        int buff = base * level;
        player.addAtk(buff);
        player.lowHpTriggered = true;

        if (level > 1) {
            cout << "[発動] " << name << "+" << (level - 1)
                << "：ATK +" << buff << endl;
        }
        else {
            cout << "[発動] " << name << "：ATK +" << buff << endl;
        }
    }
}     


void SuperLowHpAttackUp::apply(Player& player) {

    //スキルが発動しているのかの確認
    if (player.superLowHpTriggered) {
        return;
    }

    //発動条件:HP30%以下のターン開始時(戦闘中一回のみ)　　効果：その戦闘中、ATK+100%(レベルアップするごとに、追加で+100%)
    if (player.getHp() <= player.getMaxHp() * 0.3) {
        int base = static_cast<int>(player.getAtk());
        int buff = base * level;
        player.addAtk(buff);
        player.superLowHpTriggered = true;

        if (level > 1) {
            cout << "[発動] " << name << "+" << (level - 1)
                << "：ATK +" << buff << endl;
        }
        else {
            cout << "[発動] " << name << "：ATK +" << buff << endl;
        }
    }
}