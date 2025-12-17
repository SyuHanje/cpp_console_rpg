#include<iostream>
#include <vector>
#include"character.h"
#include"player.h"
#include "skill.h"

using namespace std;

//プレイヤー被弾時処理
void Player::dmg(int Value) {

    //防御時、敵のatk80%ダウン
    if (guard == true) {
        Value *= 0.2;
    }

    //ダメージ処理
    Character::dmg(Value);

    //戦闘テキスト処理
    std::cout << "敵の攻撃！プレイヤーのHPが" << hp << "になった" << endl << endl;
    if (hp == 0) {
        std::cout << "プレイヤーは倒れた！" << endl;
    }
}

//回復マス処理
void Player::heal(int trigger) {

    //ランダムマス経由
    if (trigger == 1) {
        hp += (max_hp / 5);      
    }

    //Hマス経由
    else {
        hp += (max_hp / 3);
    }

    //最大値以上には回復しない
    if (hp > max_hp) {
        hp = max_hp;
    }

    //回復テキスト処理
    cout << "回復してHPが" << hp << "になった" << endl;
}

//スキル適用関数
void Player::applySkills() {

    // 毎ターンatkを基礎値に戻す
    atk = base_atk;

    //スキル適用
    for (auto* skill : skills) {
        skill->apply(*this);
    }
}

//スキル管理関数
void Player::addSkill(Skill* newSkill) {

    //同じ名前のスキルがあったら強化
    for (auto* s : skills) {
        if (s->name == newSkill->name) {

            //レベルアップ
            s->levelUp();

            cout << "スキル強化！ " << s->name
                << " +" << (s->level - 1) << endl;

            //スキル重複防止
            delete newSkill;
            return;
        }
    }

    //同じ名前のスキルがなかったら、新規スキルとして追加
    skills.push_back(newSkill);

    cout << "スキル獲得！ " << newSkill->name
        << "（" << newSkill->description << "）" << endl;
}