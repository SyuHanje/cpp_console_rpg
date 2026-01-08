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

StatusRate Random::createPlayerStatusRate() {
    StatusRate rate;

    rate.hpRate = randomRange(80, 130);

    if (rate.hpRate > 110) {
        rate.atkRate = randomRange(70, 110);
    }
    else {
        rate.atkRate = randomRange(80, 130);
    }

    if (rate.hpRate + rate.atkRate > 220) {
        rate.defRate = randomRange(70, 130);
    }
    else {
        rate.defRate = randomRange(100, 200);
    }

    return rate;
}

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