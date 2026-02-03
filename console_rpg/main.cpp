#include<iostream>
#include "map.h"
#include "saveload.h"

using namespace std;

int main() {
    
    Map map;
    Game game;

    //セーブがあればロード、なければプレイヤーのステータスにランダム補正をかけ、マップ生成を行う
    if (map.saveLoad.load(map.player, map, 0)) {
        cout << "オートセーブをロードしました" << endl;
    }
    else {
        map.player.applyRandomStatus(
            Random::createPlayerStatusRate()
        );
        map.generateMap();
    }

    //ゲーム開始
    game.run(map, map.player, map.saveLoad);

    return 0;
}