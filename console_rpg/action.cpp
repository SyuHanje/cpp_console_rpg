#include<iostream>
#include"action.h"

using namespace std;

//戦闘中の入力とターン進行を管理
int Action::trun() {

	cout << turnNUM << "ターン目、どうすんだよ。　１、攻撃　２、防御：　";
	cin >> act;	
	cout << endl;
	
	switch (act) {
		//攻撃
	case 1:
		turnNUM++;
		return 1;

	case 2:
		//防御
		turnNUM++;
		return 2;

	default:
		//記載番号外入力
		return 3;
	}
}