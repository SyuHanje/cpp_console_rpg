#pragma once

#ifndef _ACTION_H_
#define _ACTION_H_

class Action {
public:

	//ターン進行テキスト
	int turn();

	//戦闘ターン数カウンター
	int turnNUM = 1;

protected:

	//行動トリガー
	int act = 0;
};

#endif//_ACTION_H_