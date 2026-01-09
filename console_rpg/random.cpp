#include <iostream>
#include <random>
#include <chrono>
#include "random.h"

using namespace std;

//乱数生成
static mt19937 gen(
    chrono::system_clock::now().time_since_epoch().count()
);

int Random::randomRange(int min,int max) {
    
    if (min > max) {
        swap(min, max);
    }
    uniform_int_distribution<> choose(min, max);

    return choose(gen);
}

//プレイヤーのステータス変動幅
StatusRate Random::createPlayerStatusRate() {

    StatusRate rate;

    //「防御型」「攻撃型」「バランス型」と、方向性があって、極端に強い・弱いステータスとなりにくいよう、乱数を調整
    rate.hpRate = randomRange(80, 130);

    if (rate.hpRate > 120) {
        rate.defRate = randomRange(70, 130);
    }
    else if (rate.hpRate > 90) {
        rate.defRate = randomRange(80, 150);
    }
    else {
        rate.defRate = randomRange(100, 200);
    }

    if (rate.hpRate + rate.defRate > 240) {
        rate.atkRate = randomRange(80, 110);
    }
    else if (rate.hpRate + rate.defRate > 200) {
        rate.atkRate = randomRange(100, 120);
    }
    else {
        rate.atkRate = randomRange(110, 150);
    }

    return rate;
}

//敵のステータス変動幅
StatusRate Random::createEnemyStatusRate() {
    StatusRate rate;

    rate.hpRate = randomRange(80, 120);
    rate.atkRate = randomRange(80, 120);
    rate.defRate = randomRange(80, 150);

    return rate;
}

//以下、呼び出しに応じて乱数範囲を設定

//敵エンカウント時
int Random::createEnemy() {

    int r = randomRange(0, 99);

    if (r < 25) {
        return 0;
    }
    if (r < 50) {
        return 1;
    }
    if (r < 75) {
        return 2;
    }
    return 3;
}

//ランダムイベント時
int Random::randomEvent() {

    int r = randomRange(0, 99);

    if (r < 40) {
        return 0;
    }
    if (r < 60) {
        return 1;
    }
    if (r < 80) {
        return 2;
    }
    return 3;
}

//ノーマルスキル抽選時
int Random::chooseNormalSkill() {
    int r = randomRange(0, 99);

    if (r < 20) {
        return 0;
    }
    if (r < 40) {
        return 1;
    }
    if (r < 60) {
        return 2;
    }
    if (r < 80) {
        return 3;
    }
    return 4;
}

//強スキル抽選時
int Random::chooseSpecialSkill() {
    int r = randomRange(0, 99);

    if (r < 20) {
        return 0;
    }
    if (r < 40) {
        return 1;
    }
    if (r < 60) {
        return 2;
    }
    if (r < 80) {
        return 3;
    }
    return 4;
}