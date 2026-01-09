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
    std::cout << "敵の攻撃！プレイヤーのHPが" << getHp() << "になった" << endl << endl;
    if (!alive()) {
        std::cout << "プレイヤーは倒れた！" << endl;
    }
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

//スキルなどの攻撃加算処理
void Player::addAtk(int value) {
    atk += value;
}


//回復処理
void Player::healByRate(float rate) {
    int amount = static_cast<int>(max_hp * rate);
    recover(amount);

    cout << "HPが回復した！（現在 " << getHp() << "）" << endl;
}

//プレイヤーのステータス初期値変動
void Player::applyRandomStatus(const StatusRate& rate) {

    //基礎値の保存
    const int baseAtk = atk;
    const int baseHp = max_hp;
    const int baseDef = def;

    //乱数をステータスに加算
    atk = atk * rate.atkRate / 100;
    max_hp = max_hp * rate.hpRate / 100;
    def = def * rate.defRate / 100;

    hp = max_hp;
    base_atk = atk;

    //変動後ステータス表示
    cout << "プレイヤーの初期ステータス　"
        << "HP:" << getMaxHp() << "（" << rate.hpRate << "%）"
        << "ATK:" << getAtk() << "（" << rate.atkRate << "%）"
        << "DEF:" << getDef() << "（" << rate.defRate << "%）" << endl;
}