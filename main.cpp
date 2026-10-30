#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// コールバック関数のポインタ型を定義
typedef void (*Callback)(int result);

// サイコロの出目を決定する関数
int roll_dice() {
    return rand() % 6 + 1;
}

// メイン関数
int main() {
    //コンソールを UTF-8 にする設定
    system("chcp 65001 > nul");

    srand((unsigned int)time(NULL));

    int dice_result = roll_dice();

    // 判定処理をキャプチャなしのラムダ式で定義
    Callback callback = [](int result) {
        int input;

        printf("サイコロの出目が奇数(1)か偶数(2)か入力:");
        scanf_s("%d", &input);

        printf("判定中...\n");
        Sleep(3000);

        // 出目の奇数・偶数と入力が一致するか判定
        if ((result % 2 == 1 && input == 1) ||
            (result % 2 == 0 && input == 2)) {
            printf("正解\n");
        } else {
            printf("不正解\n");
        }

        printf("サイコロの目は%d\n", result);
        };

    // サイコロの値を引数にして関数ポインタから実行
    callback(dice_result);

    return 0;
}