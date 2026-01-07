#include <iostream>
#include <random>
#include <chrono>
#include "game.h"

using namespace std;

//戦闘開始
int Game::start(Player& player) {
    cout << "戦闘開始！" << endl;
    Enemy enemy(Random::createEnemy());

    cout << "出現: " << enemy.getName() << " が現れた！" << endl;

    //雑魚戦用遷移
    battle(player, enemy);

    cout << "戦闘終了！" << endl;

    //ターン数リセット
    act.turnNUM = 1;

    //プレイヤーの生存トリガー確認
    return player.alive() ? 0 : -2;
}

//戦闘開始(ボス用)
void Game::boss_start(Player& player) {
    cout << "戦闘開始！" << endl;

    //ボス戦用セッティング
    Enemy enemy(4);
    cout << "出現:" << enemy.getName() << " が現れた！" << endl;

    //ボス戦用遷移
    battle(player,enemy);
    cout << "戦闘終了！" << endl;
}

void Game::battle(Player& player, Enemy& enemy) {

    while (enemy.alive() && player.alive()) {

        // スキル発動確認
        player.applySkills();

        //1、敵に攻撃　2、防御有効化  3、その他数字番号
        switch (act.turn()) {

        case 1:
            enemy.dmg(player.getAtk());
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
            player.dmg(enemy.getAtk());
        }

        //防御を無効化
        player.guard = false;
    }

    //スキル発動トリガーをリセット
    player.lowHpTriggered = false;
    player.superLowHpTriggered = false;
}