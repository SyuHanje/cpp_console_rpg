#pragma once

#ifndef _RANDOM_H_
#define _RANDOM_H_

//ステータス変動用乱数
struct StatusRate {
	int atkRate;
	int hpRate;
	int defRate;
};

class Random {
public:
	//乱数生成
	static int randomRange(int,int);

	//ランダム性があるイベントの処理
	static int createEnemy();
	static int randomEvent();
	static int chooseNormalSkill();
	static int chooseSpecialSkill();

	//マス生成確率コントロール
	static int randomCellChoice(int);
	//マス生成処理
	static int randomCellType(int);

	//ステータスの初期変動関数
	static StatusRate createPlayerStatusRate();
	static StatusRate createEnemyStatusRate();

private:
	//生成したマスの総数
	static int Cell;
	//生成した特殊マスのカウント
	static int healCell;
	static int skillCell;
};

#endif //_RANDOM_H_
