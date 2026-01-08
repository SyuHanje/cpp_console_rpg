#pragma once

#ifndef _RANDOM_H_
#define _RANDOM_H_


struct StatusRate {
	int atkRate;
	int hpRate;
	int defRate;
};

class Random {
public:
	static int randomRange(int,int);
	static int createEnemy();
	static int randomEvent();
	static int chooseNormalSkill();
	static int chooseSpecialSkill();

	static StatusRate createPlayerStatusRate();
	static StatusRate createEnemyStatusRate();
};

#endif //_RANDOM_H_
