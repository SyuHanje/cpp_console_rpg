#include<iostream>
#include "map.h"
#include "saveload.h"

using namespace std;

int main() {
    //ゲーム開始
    Map map;

    if (map.saveLoad.load(map.player, map, 0)) {
        cout << "オートセーブをロードしました\n";
    }
    else {
        // セーブが無いときだけ
        map.player.applyRandomStatus(
            Random::createPlayerStatusRate()
        );
    }

    map.map_main();

    return 0;
}