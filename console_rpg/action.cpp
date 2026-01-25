#include<iostream>
#include"action.h"

using namespace std;

//戦闘中の入力とターン進行を管理
ActionType Action::next() {
    int act;

    cout << turnNUM << "ターン目、どうすんだよ。 1:攻撃 2:防御 ";
    cin >> act;

    turnNUM++;

    if (act == 1) {
        return ActionType::Attack;
    }
    if (act == 2) {
        return ActionType::Guard;
    }

    return ActionType::Invalid;
}