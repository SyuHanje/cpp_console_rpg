#include <iostream>
#include "battle.h"

using namespace std;

void Battle::run(Player& player, Enemy& enemy) {

    //ターン数リセット
    act.turnNUM = 1;

    while (enemy.alive() && player.alive()) {

        // スキル発動確認
        player.applySkills();

        //コマンド入力
        ActionType action = act.next();

        // 行動選択
        switch (action) {

        case ActionType::Attack:
            enemy.dmg(player.getAtk());
            break;

        case ActionType::Guard:
            player.guard = true;
            break;

        case ActionType::Invalid:
            cout << "文字が読めないんか？？？" << endl;
            continue;
        }

        // 敵の攻撃
        if (enemy.alive() && player.alive()) {
            player.dmg(enemy.getAtk());
        }

        // 防御解除
        player.guard = false;
    }

    // スキルトリガーリセット
    player.lowHpTriggered = false;
    player.superLowHpTriggered = false;
}