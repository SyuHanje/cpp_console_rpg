#pragma once
#include <string>
#include <vector>
#include "Character.h"
#include "skill.h"
//味方ステータス

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player : public Character {
public:

	int base_atk;
	int LowHpLevel = 0;
	int superLowHpLevel = 0;

	// スキル一度きり発動トリガー
	bool lowHpTriggered = false;
	bool superLowHpTriggered = false;

	//防御トリガー
	bool guard = false;

	// 獲得したスキル一覧
	std::vector<Skill*> skills; 

	//プレイヤーステータス設定
	Player() : Character("プレイヤー", 20, 100, 0, 100) {
		base_atk = atk;
	}

	//戦闘処理(プレイヤー)
	void dmg(int) override;

	//回復マス処理
	void heal(int);

	//スキル適用関数
	void applySkills();

	//スキル獲得・強化関数
	void addSkill(Skill* skill);
};

#endif //_PLAYER_H_