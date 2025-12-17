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

    /*純粋仮想関数。これがあるクラスは抽象クラスだというらしい。
    中身はスキルの内容処理で、ここにあるのは「絶対にスキルではこれを使え」っていう型。
    こうすれば他のクラスでスキルを呼び出すときは、applyだけで済む...って認識している(2025/11/17)*/
    virtual void apply(Player& player) = 0;
    
    //スキルのレベルアップ用関数
    virtual void levelUp() {
        level++;
    }
};

//スキル抽選用関数
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