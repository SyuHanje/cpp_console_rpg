#include<iostream>
#include"action.h"

using namespace std;

ActionType Action::next() {
    int act;

    cout << turnNUM << "ƒ^[ƒ“–ÚA‚Ç‚¤‚·‚ñ‚¾‚æB ‚P:UŒ‚ ‚Q:–hŒä ";
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