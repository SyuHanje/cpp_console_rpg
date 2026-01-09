#include<iostream>
#include"enemy.h"
#include"character.h"

using namespace std;

//敵リスト
Enemy::Enemy(int type) : Character("敵", 15, 100, 0, 100) {

    //敵ステータスを変動させる乱数
    StatusRate rate = Random::createEnemyStatusRate();

    switch (type) {
    case 0:
        setName("悪いスライム");
        setStatus(10 * rate.atkRate / 100,
                  50 * rate.hpRate / 100,
                  2 * rate.defRate / 100);
        break;
    case 1:
        setName("スレイヤーされしゴブリン");
        setStatus(10 * rate.atkRate / 100,
                  80 * rate.hpRate / 100,
                  4 * rate.defRate / 100);
        break;
    case 2:
        setName("娘攫いのオーク");
        setStatus(10 * rate.atkRate / 100,
                  120 * rate.hpRate / 100,
                  6 * rate.defRate / 100);
        break;
    case 3:
        setName("「D」ドラゴン");
        setStatus(10 * rate.atkRate / 100,
                  200 * rate.hpRate / 100,
                  10 * rate.defRate / 100);
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