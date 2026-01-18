#include<iostream>
#include "map.h"
#include "saveload.h"

using namespace std;

int main() {
    
    Map map;

    //セーブがあればロード、なければプレイヤーのステータスにランダム補正をかける
    if (map.saveLoad.load(map.player, map, 0)) {
        cout << "オートセーブをロードしました" << endl;
    }
    else {
        map.player.applyRandomStatus(
            Random::createPlayerStatusRate()
        );
    }

    //ゲーム開始
    map.map_main();

    return 0;
}