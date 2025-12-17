#include<iostream>
#include"enemy.h"
#include"character.h"

using namespace std;

//敵リスト
Enemy::Enemy(int type) : Character("敵", 15, 100, 0, 100) {
    switch (type) {
    case 0:
        name = "悪いスライム";
        atk = 10;
        hp = max_hp = 50;
        def = 2;
        break;
    case 1:
        name = "スレイヤーされしゴブリン";
        atk = 10;
        hp = max_hp = 80;
        def = 4;
        break;
    case 2:
        name = "娘攫いのオーク";
        atk = 10;
        hp = max_hp = 120;
        def = 6;
        break;
    case 3:
        name = "「D」ドラゴン";
        atk = 10;
        hp = max_hp = 200;
        def = 10;
        break;
    default:
        name = "深淵で覗き返すモノ";
        atk = 50;
        hp = max_hp = 300;
        def = 5;
        break;
    }
}

//被ダメージ時のテキスト表示
void Enemy::dmg(int Value) {

    //ダメージ処理
    Character::dmg(Value);

    //敵被ダメージ時のテキスト表示
    cout << "プレイヤーの攻撃！敵のHPが" << hp << "になった" << endl;
    if (hp == 0) {
        cout << "敵は倒れた！" << endl;
    }
}