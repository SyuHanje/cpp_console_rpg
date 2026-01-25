#pragma once

#ifndef _ACTION_H_
#define _ACTION_H_

enum class ActionType {
	Attack,
	Guard,
	Invalid
};

class Action {
public:

	ActionType next();

	//戦闘ターン数カウンター
	int turnNUM = 1;
};

#endif//_ACTION_H_