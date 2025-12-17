#pragma once
#include <string>

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

class Character {

	//基礎ステータス
public:
	int atk;
	int hp;
	int max_hp;
	int def;
	std::string name;

	Character(std::string n, int a, int h, int d, int m)
		: name(n), atk(a), hp(h), def(d) ,max_hp(m){
	}

	//ダメージ処理
	virtual void dmg(int);

	//生存トリガー
	bool alive();
};

#endif//_CHARACTER_H_