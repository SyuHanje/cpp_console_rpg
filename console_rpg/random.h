#pragma once

#ifndef _RANDOM_H_
#define _RANDOM_H_

class Random {
public:
	static int randomRange(int,int);
	static int createEnemy();
	static int randomEvent();
	static int chooseNormalSkill();
	static int chooseSpecialSkill();
};

#endif //_RANDOM_H_
