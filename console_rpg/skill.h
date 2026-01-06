#pragma once
#include <string>
#include <vector>

class Player;

//スキル基礎データ
class Skill {
public:
    std::string name;
    std::string description;
    int level = 1;

    Skill(std::string n, std::string d)
        : name(n), description(d) {
    }

    virtual void apply(Player& player) = 0;
    
    //スキルのレベルアップ用関数
    virtual void levelUp() {
        level++;
    }
};

Skill* createNormalSkill(int raffle);
Skill* createSpecialSkill(int raffle);

//以下、スキル本体のクラス
class LowHpAttackUp : public Skill {
public:
    LowHpAttackUp() : Skill("戦いの勘", "発動条件:HP80%以下のターン開始時(戦闘中一回のみ)　　効果：その戦闘中、ATK+30%(レベルアップするごとに、追加で+30%)") {}
    void apply(Player& player) override;
};

class SuperLowHpAttackUp : public Skill {
public:
    SuperLowHpAttackUp() : Skill("根源の力", "発動条件:HP30%以下のターン開始時(戦闘中一回のみ)　　効果：その戦闘中、ATK+100%(レベルアップするごとに、追加で+100%)") {}
    void apply(Player& player) override;
};