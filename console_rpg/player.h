#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <vector>
#include "character.h"
#include "skill.h"
#include "random.h"

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

	//プレイヤーステータス
	Player() : Character("プレイヤー", 20, 100, 3, 100) {
		base_atk = atk;
	}

	//戦闘処理(プレイヤー)
	void dmg(int) override;


	//スキル適用関数
	void applySkills();

	//スキル獲得・強化関数
	void addSkill(Skill* skill);

	void addAtk(int value);

	//回復量・テキスト
	void healByRate(float);

	//初期ステータス変動関数
	void applyRandomStatus(const StatusRate&);

	void clearSkills();
	void addSkillByName(const std::string& name, int level);
};

#endif //_PLAYER_H_