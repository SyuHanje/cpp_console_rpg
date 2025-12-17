#include <iostream>
#include <random>
#include <chrono>
#include "game.h"

using namespace std;

//戦闘開始
int Game::start(Player& player) {
    cout << "戦闘開始！" << endl;

    //乱数で出現敵抽選
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<> choose(0, 3);

    int enemyType = choose(gen);
    Enemy enemy(enemyType);

    cout << "出現: " << enemy.name << " が現れた！" << endl;

    //雑魚戦用遷移
    battle(player, enemy);

    cout << "戦闘終了！" << endl;

    //ターン数リセット
    act.turnNUM = 1;

    //プレイヤーの生存トリガー確認
    return player.alive() ? 0 : -2;
    /*注：三項演算子ってやつらしい。「条件式 ? 条件がtrueのときの値 : 条件がfalseのときの値」
    if (player.alive()) {
        return 0;
    }
    else {
        return -2;
    }
    を一行にまとめた処理*/
}

//戦闘開始(ボス用)
void Game::boss_start(Player& player) {
    cout << "戦闘開始！" << endl;

    //ボス戦用セッティング
    Enemy enemy(4);
    cout << "出現:" << enemy.name << " が現れた！" << endl;

    //ボス戦用遷移
    battle(player,enemy);
    cout << "戦闘終了！" << endl;
}

void Game::battle(Player& player, Enemy& enemy) {

    while (enemy.alive() && player.alive()) {

        // スキル発動確認
        player.applySkills();

        //1、敵に攻撃　2、防御有効化  3、その他数字番号
        switch (act.trun()) {

        case 1:
            enemy.dmg(player.atk);
            break;

        case 2:
            player.guard = true;
            break;

        case 3:
            cout << "文字が読めないんか？？？" << endl;
            continue;
        }

        //敵の攻撃
        if (enemy.alive() && player.alive()) {
            player.dmg(enemy.atk);
        }

        //防御を無効化
        player.guard = false;
    }

    //戦闘終了時にプレイヤーを小回復
    if (player.alive()) {
        player.hp += 20;
        if (player.hp > player.max_hp) player.hp = player.max_hp;
        cout << "プレイヤーは20回復した！（" << player.hp << "までhpが回復した" "）" << endl;
    }

    //スキル発動トリガーをリセット
    player.lowHpTriggered = false;
    player.superLowHpTriggered = false;
}