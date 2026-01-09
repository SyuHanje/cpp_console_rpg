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

	//ステータスの初期変動関数
	static StatusRate createPlayerStatusRate();
	static StatusRate createEnemyStatusRate();
};

#endif //_RANDOM_H_
