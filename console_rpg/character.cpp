#include<iostream>
#include"character.h"
#include"skill.h"
#include<string>

using namespace std;

//ダメージ処理(敵味方共通)
void Character::dmg(int Value) {

    //atk-def=ダメージ量
    Value -= def;

    //ダメージ量とhpの最低値を0とする
    if (Value < 0) {
        Value = 0;
    }
    hp -= Value;
    if (hp < 0) {
        hp = 0;
    }
}

//生存確認トリガー
bool Character::alive() const {
    return hp > 0;
}

//ステータス取得
int Character::getHp() const { 
    return hp; 
}

int Character::getAtk() const { 
    return atk; 
}

int Character::getDef() const { 
    return def; 
}

int Character::getMaxHp() const {
    return max_hp; 

}

const std::string& Character::getName() const {
    return name;
}

//回復関数
void Character::recover(int amount) {
    if (amount <= 0) return;

    hp += amount;
    if (hp > max_hp) {
        hp = max_hp;
    }
}

void Character::setStatus(int a, int h, int d) {
    atk = a;
    hp = h;
    max_hp = h;
    def = d;
}

void Character::setName(const std::string& n) {
    name = n;
}