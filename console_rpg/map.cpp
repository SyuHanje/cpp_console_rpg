#include<iostream>
#include <random>
#include <chrono>
#include"map.h"

using namespace std;

void Map::map_main() {

    //マップ表示
    map_display();
    
    //イベント値が-1の場合ゲーム終了（ゲームクリア）
    while (event != -1) {

        //マップ上移動＆イベント管理関数
        move();
        event_display();

        //ゲームオーバー時の処理
        if (event == -2) {
            cout << "[Game over]";
            return;
        }
    }
}

int Map::map_display() {

    //壁であるかどうか
    if (map[x][y] == -1) {
        return -1;
    }

    //イベントトリガーに現在地を代入
    Map::event = map[x][y];

    //移動
    map[x][y] = 1;
    cout << endl;

    //マップ表示(■:移動不可マス　□:ランダムマス  P:プレイヤー現在地　H:回復マス　E:パッシブスキル獲得マス　B:ボス戦)
    for (int i = 0;i < max_x; i++) {
        for (int f = 0; f < max_y; f++) {
            switch (map[i][f]) {
            case -1:
                cout << "■ ";
                break;
            case 0:
                cout << "□ ";
                break;
            case 1:
                cout << "P ";
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
            }
        }
        cout << endl;
    }

    //通過した場所を移動不可にする
    map[x][y] = -1;

    //次ターンに移動するスペースがあるか確認
    if (map[x][y + 1] >= 0 ||
        map[x][y - 1] >= 0 ||
        map[x + 1][y] >= 0 ||
        map[x - 1][y] >= 0) {

        return 0;
    }
    else {
        //ゲームオーバー
        event = -2;
        return -2;
    }
}

void Map::move() {
    int menu_no;
    while (1) {

        //値を手に入れる(移動確認＆移動不可時のリセット用)
        int move_x = x, move_y = y;

        //移動メニュー
        cout << endl << "[移動メニュー]" << endl << "1:←　 2 :↑　 3 :→ 　4 :↓" << endl;
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
        }

        //移動可能であることの確認
        if (move_x >= 0 && x <= max_x && move_y >= 0 && y <= max_y) {
            //壁に当たった場合
            if (map_display() != -1) {
                return;
            }
            cout << "壁です";
        }

        //移動可時マスがない時の処理
        else if (event == -2) {
            return;
        }

        //移動不可時マスに侵入しようとする時の処理（移動前の位置に戻す）
        x = move_x;
        y = move_y;

        map_display();
    }
}

void Map::event_display() {
    //ランダムイベント・スキル抽選用乱数
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    mt19937 gen(seed);
    uniform_int_distribution<> choose(0, 4);
    switch (event) {

        //□マス侵入時
    case 0: {

        //40%で戦闘、20%で弱スキル獲得、20%で回復、20%でスカ
        switch (choose(gen)) {
        case 0:
        case 1:
            event = game.start(player);
            break;
        case 2: {
            Skill* s = createNormalSkill(choose(gen));
            player.addSkill(s);
            break;
        }
        case 3:
            player.heal(1);
            break;
        case 4:
            cout << "しかしなにも起こらなかった" << endl;
            break;
        }
        break;
    }

          //Hマス侵入時
    case 2: {
        player.heal(2);
        break;
    }

          //Eマス侵入時
    case 3: {
        Skill* s = createSpecialSkill(choose(gen));
        player.addSkill(s);
        break;
    }

          //Bマス侵入時
    case 4: {
        game.boss_start(player);
        cout << "魔王が現れた" << endl;
        event = -1;
    }

    default: {
        break;
    }
    }
}