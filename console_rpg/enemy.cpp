#include<iostream>
#include"enemy.h"
#include"character.h"

using namespace std;

//敵リスト
Enemy::Enemy(int type) : Character("敵", 15, 100, 0, 100) {
    switch (type) {
    case 0:
        setName("悪いスライム");
        setStatus(10, 50, 2);
        break;
    case 1:
        setName("スレイヤーされしゴブリン");
        setStatus(10, 80, 4);
        break;
    case 2:
        setName("娘攫いのオーク");
        setStatus(10, 120, 6);
        break;
    case 3:
        setName("「D」ドラゴン");
        setStatus(10, 200, 10);
        break;
    default:
        setName("深淵で覗き返すモノ");
        setStatus(50, 300, 5);
        break;
    }
}

//被ダメージ時のテキスト表示
void Enemy::dmg(int Value) {

    //ダメージ処理
    Character::dmg(Value);

    //敵被ダメージ時のテキスト表示
    cout << "プレイヤーの攻撃！敵のHPが" << getHp() << "になった" << endl;
    if (!alive()) {
        cout << "敵は倒れた！" << endl;
    }
}