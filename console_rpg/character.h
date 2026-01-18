#pragma once
#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>

class Character {

	//基礎ステータス取得・代入
public:
    bool alive() const;

    int getHp() const;
    int getAtk() const;
    int getDef() const;
    int getMaxHp() const;
    const std::string& getName() const;

    void setHp(int);
    void setMaxHp(int);
    void setAtk(int);
    void setDef(int);

    //回復関連
    void recover(int amount);

    //ダメージ処理関数
    virtual void dmg(int);

    //基礎ステータス
protected:
    int atk;
    int hp;
    int max_hp;
    int def;
    std::string name;

    Character(std::string n, int a, int h, int d, int m)
        : name(std::move(n)), atk(a), hp(h), def(d), max_hp(m) {
    }

    void setStatus(int a, int h, int d);
    void setName(const std::string& n);
};

#endif//_CHARACTER_H_