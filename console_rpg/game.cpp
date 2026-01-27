#include <iostream>
#include <random>
#include <chrono>
#include "game.h"

using namespace std;

//ゲームコントロール
void Game::run(Map& map, Player& player, SaveLoad& saveLoad) {

    int event = 0;

    while (event != -1) {
        
        //マップ表示
        map.map_display();

        //マップ移動
        map.move();

        int x = map.getX();
        int y = map.getY();


        event = map.getMap()[x][y];
        map.setMapCell(x, y, -1);

        int cell = map.getMap()[x][y];
        map.setMapCell(x, y, -1);

        // 詰み判定
        if (!(map.getMap()[x][y + 1] >= 0 ||
            map.getMap()[x][y - 1] >= 0 ||
            map.getMap()[x + 1][y] >= 0 ||
            map.getMap()[x - 1][y] >= 0)) {

            cout << "[Game over]";
            saveLoad.erase(0);
            return;
        }

        //ランダムイベント
        event = handleMapEvent(event, player, saveLoad);

        if (event == -2) {
            cout << "[Game over]";
            saveLoad.erase(0);
            return;
        }
    }
}

//ランダムイベント抽選
int Game::handleMapEvent(int cell, Player& player, SaveLoad& saveLoad) {

    switch (cell) {

    case 0: {

        //40%で戦闘、20%で弱スキル獲得、20%で回復、20%でスカ
        switch (Random::randomEvent()) {
        case 0:
            return start(player);
            break;
        case 1: {
            Skill* s = createNormalSkill(Random::chooseNormalSkill());
            player.addSkill(s);
            break;
        }
        case 2:
            player.healByRate(0.2f);
            break;
        case 3:
            cout << "しかしなにも起こらなかった" << endl;
            break;
        }
        break;
    }

          //Hマス侵入時
    case 2: {
        player.healByRate(0.4f);
        break;
    }

          //Eマス侵入時
    case 3: {
        Skill* s = createSpecialSkill(Random::chooseSpecialSkill());
        player.addSkill(s);
        break;
    }

          //Bマス侵入時
    case 4: {
        boss_start(player);
        cout << "魔王が現れた" << endl;

        saveLoad.erase(0);
        return -1;
        break;
    }

          //例外処理
    default: {
        break;
    }

           return 0;
    }
}

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