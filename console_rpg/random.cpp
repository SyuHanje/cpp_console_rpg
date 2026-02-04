#include <iostream>
#include <random>
#include <chrono>
#include "random.h"

using namespace std;

//マスカウント
int Random::Cell = 0;
int Random::healCell = 0;
int Random::skillCell = 0;

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

//マス生成の確率管理
int Random::randomCellChoice(int x) {
    int Row = 0;

    //最初の一列は通常確率
    if (Cell < 10) {
        return randomCellType(x);
    }
    //二列目以降は特殊マスの割合から確率調整
    return randomCellType(x);
}

//マップ構成ランダム抽選(通常)
int Random::randomCellType(int Row) {
    int r = randomRange(0, 99);
    Cell++;

    //スタート地点からの距離に応じて確率変化
    if (Row < 5) {
        //ランダムマス
        if (r < 60) {
            return 0;
        }

        //回復
        if (r < 80) {
            healCell++;
            return 2;
        }

        //スキル
        if (r < 100) {
            skillCell++;
            return 3;
        }
    }

    if (Row < 8) {
        //ランダムマス
        if (r < 70) {
            return 0;
        }

        //回復
        if (r < 85) {
            healCell++;
            return 2;
        }

        //スキル
        if (r < 100) {
            skillCell++;
            return 3;
        }
    }

    if (Row < 11) {
        //ランダムマス
        if (r < 90) {
            return 0;
        }

        //回復
        if (r < 100) {
            healCell++;
            return 2;
        }
    }

    return 0;
}