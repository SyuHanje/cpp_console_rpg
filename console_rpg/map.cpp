#include<iostream>
#include"map.h"

using namespace std;

void Map::map_main() {
    
    //イベント値が-1の場合ゲーム終了（ゲームクリア）
    while (event != -1) {

        //マップ表示
        map_display();

        //マップ上移動＆イベント管理関数
        move();
        event_display();

        //ゲームオーバー時の処理
        if (event == -2) {
            cout << "[Game over]";
            //セーブ削除
            saveLoad.erase(0);
            return;
        }
    }
}

//マップ表示
void Map::map_display() {

    cout << endl;

    for (int i = 0; i < max_x; i++) {
        for (int j = 0; j < max_y; j++) {

            if (i == x && j == y) {
                cout << "P ";
                continue;
            }

            //■：通過不可　□：ランダムマス　H：回復マス　E：強スキル獲得マス　B：ボスマス　S：スタート地点(入っても反応なし)
            switch (map[i][j]) {
            case -1: 
                cout << "■ "; 
                break;
            case 0:  
                cout << "□ ";
                break;
            case 2:  
                cout << "H ";
                break;
            case 3: 
                cout << "E ";
                break;
            case 4:  
                cout << "B "; 
                break;
            default: 
                cout << "S ";
                break;
            }
        }
        cout << endl;
    }
}

//移動選択
void Map::move() {

    int menu_no;

    while (true) {

        int old_x = x;
        int old_y = y;

        saveLoad.save(player, *this, 0);

        cout << endl
            << "[移動メニュー]" << endl
            << "1:←  2:↑  3:→  4:↓" << endl;

        cin >> menu_no;

        switch (menu_no) {
        case 1: y--; break;
        case 2: x--; break;
        case 3: y++; break;
        case 4: x++; break;
        default:
            x = old_x;
            y = old_y;
            continue;
        }

        //範囲外
        if (x < 0 || x >= max_x || y < 0 || y >= max_y) {
            cout << "そこには行けない" << endl;
            x = old_x;
            y = old_y;
            continue;
        }

        //壁
        if (map[x][y] == -1) {
            cout << "壁です" << endl;
            x = old_x;
            y = old_y;
            continue;
        }

        //移動確定
        applyMove();
        return;
    }
}

void Map::event_display() {
    //ランダムイベント
    switch (event) {

        //□マス侵入時
    case 0: {

        //40%で戦闘、20%で弱スキル獲得、20%で回復、20%でスカ
        switch (Random::randomEvent()) {
        case 0:
            event = game.start(player);
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
        game.boss_start(player);
        cout << "魔王が現れた" << endl;

        saveLoad.erase(0);
        event = -1;
        break;
    }

          //例外処理
    default: {
        break;
    }
    }
}

//移動処理
void Map::applyMove() {

    //イベント取得
    event = map[x][y];

    //通過済みにする
    map[x][y] = -1;

    //次に動ける場所があるか確認
    if (!(map[x][y + 1] >= 0 ||
        map[x][y - 1] >= 0 ||
        map[x + 1][y] >= 0 ||
        map[x - 1][y] >= 0)) {

        //ゲームオーバー
        event = -2;
        saveLoad.erase(0);
    }
}

//マップのセーブ＆ロード用
int Map::getX() const { return x; }
int Map::getY() const { return y; }
void Map::setPosition(int px, int py) { x = px; y = py; }

int(&Map::getMap())[5][12]{
    return map;
}
const int(&Map::getMap() const)[5][12]{
    return map;
}

void Map::setMapCell(int i, int j, int value) {
    map[i][j] = value;
}