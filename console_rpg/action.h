#pragma once

#ifndef _ACTION_H_
#define _ACTION_H_

//コマンド種類
enum class ActionType {
	Attack,
	Guard,
	Invalid
};

class Action {
public:

	//行動選択＆ターン数加算
	ActionType next();

	//戦闘ターン数カウンター
	int turnNUM = 1;
};

#endif//_ACTION_H_