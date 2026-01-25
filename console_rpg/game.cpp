#include <iostream>
#include <random>
#include <chrono>
#include "game.h"

using namespace std;

//戦闘開始
int Game::start(Player& player) {
    cout << "戦闘開始！" << endl;

    //敵抽選
    Enemy enemy(Random::createEnemy());

    cout << "出現: " << enemy.getName() << " が現れた！" << endl;

    //戦闘処理
    Battle battle;
    battle.run(player, enemy);

    cout << "戦闘終了！" << endl;

    return player.alive() ? 0 : -2;
}

//戦闘開始(ボス用)
void Game::boss_start(Player& player) {
    cout << "戦闘開始！" << endl;

    //ボス戦用セッティング
    Enemy enemy(4);
    cout << "出現:" << enemy.getName() << " が現れた！" << endl;

    //戦闘処理
    Battle battle;
    battle.run(player, enemy);

    cout << "戦闘終了！" << endl;
}