#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// 判定関数のプロトタイプ宣言
void ShowResult(int roll, int userGuess);

// 遅延実行関数のプロトタイプ宣言
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess);

// サイコロの出目を決定する関数
int RollDice() {
    return rand() % 6 + 1;
}

// 判定関数(コールバック関数)
void ShowResult(int roll, int userGuess) {

    printf("出目は%dでした。\n", roll);

    // 奇数なら roll % 2 == 1、偶数なら roll % 2 == 0
    if ((userGuess == 1 && roll % 2 == 1) || (userGuess == 0 && roll % 2 == 0)) {
        printf("正解\n");
    } else {
        printf("不正解\n");
    }
}

// 遅延実行関数
// fn        : 呼び出したい関数へのポインタ
// delayMs   : 待機時間(ミリ秒)
// roll      : サイコロの出目
// userGuess : ユーザーの入力(1=奇数, 0=偶数)
void DelayReveal(void (*fn)(int, int), unsigned int delayMs, int roll, int userGuess) {

    printf("判定中...\n");

    Sleep(delayMs);

    // 関数ポインタから関数を呼び出す
    fn(roll, userGuess);
}

// メイン関数
int main() {
    //コンソールを UTF-8 にする設定
    system("chcp 65001 > nul");

    // 乱数の初期化
    srand((unsigned)time(NULL));

    // ユーザーの入力
    int userGuess;
    printf("半(奇数)なら1、丁(偶数)なら0を入力してください:");
    scanf_s("%d", &userGuess);

    // サイコロの出目を生成
    int roll = RollDice();

    // 3秒後に結果を表示
    DelayReveal(ShowResult, 3000, roll, userGuess);

    return 0;
}