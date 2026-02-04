#include<iostream>
#include"map.h"

using namespace std;

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
        case 1: 
            y--; 
            break;
        case 2: 
            x--; 
            break;
        case 3: 
            y++; 
            break;
        case 4:
            x++;
            break;
        default:
            x = old_x;
            y = old_y;
            continue;
        }

        //範囲外
        if (x < 0 || x >= max_x || y < 0 || y >= max_y) {
            cout << "Void" << endl;
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

        return;
    }
}

//マップのセーブ＆ロード用
int Map::getX() const { 
    return x;
}
int Map::getY() const {
    return y;
}
void Map::setPosition(int px, int py) { 
    x = px; y = py;
}

int(&Map::getMap())[5][12]{
    return map;
}
const int(&Map::getMap() const)[5][12]{
    return map;
}

void Map::setMapCell(int i, int j, int value) {
    map[i][j] = value;
}

//マップ生成
void Map::generateMap() {
    for (int y = 1; y < 5 - 1; y++) {
        for (int x = 1; x < 12 - 1; x++) {

            //スタート地点固定
            if (y == 3 && x == 1) {
                map[y][x] = 1;
                continue;
            }
            //ボス地点固定
            if (y == 1 && x == 10) {
                map[y][x] = 4;
                continue;
            }

            //その他のマスはランダム抽選
            map[y][x] = Random::randomCellChoice(x);
        }
    }
}