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
bool Character::alive() {

    //hpが0より大きい場合に生存判定を返す
	return hp > 0;
}