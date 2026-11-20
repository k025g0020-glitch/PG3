#include <iostream>
#include <stdlib.h>
using namespace std;

class Enemy {
public:
    void Update();

    void Approach(); // 接近
    void Shoot();    // 射撃
    void Retreat();  // 離脱

    // 関数ポインタテーブル
    static void (Enemy::* table[])();
private:
    int index = 0;
};

void Enemy::Approach() { cout << "敵が接近！" << endl; }

void Enemy::Shoot() { cout << "敵が射撃！" << endl; }

void Enemy::Retreat() { cout << "敵が離脱" << endl; }

void Enemy::Update() {

    // 関数テーブルから関数を実行
    (this->*table[index])();

    cout << "次の状態に移行 (0: はい、 他: いいえ)";
    int input;
    cin >> input;

    if (input == 0) { index = (index + 1) % 3; }
}

// メンバ関数ポインタテーブル
void (Enemy::* Enemy::table[])() = {
    &Enemy::Approach, // インデックス0
    &Enemy::Shoot,    // インデックス1
    &Enemy::Retreat   // インデックス2
};

int main() {
    //コンソールを UTF-8 にする設定
    system("chcp 65001 > nul");

    Enemy enemy;
    while (1) enemy.Update();
    return 0;
}