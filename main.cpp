#include <stdio.h>
#include <stdlib.h>

//一般的な賃金体系の時給
const int IPPAN_JIKYU = 1226;

//再帰的な賃金体系と一般的な賃金体系を1時間ずつ比較する
//kyuuryou : 再帰的な賃金体系でのその1時間の時給
//saikiSum : 再帰的な賃金体系での給料の合計
//zikan    : 働いた時間
//ippanSum : 一般的な賃金体系での給料の合計
int Recursive(int kyuuryou, int saikiSum, int zikan, int ippanSum) {
	printf("%2d時間目  再帰的: 時給%6d円 合計%7d円  一般的: 合計%7d円\n",
		zikan, kyuuryou, saikiSum, ippanSum);

	//再帰的な賃金体系の合計が一般的な賃金体系の合計を超えたら終了
	if (saikiSum > ippanSum) {
		printf("\n%d時間働くと、再帰的な賃金体系のほうが儲かる\n", zikan);
		return zikan;
	}

	//次の1時間の時給は「前の1時間でもらった時給 * 2 - 50円」
	int nextKyuuryou = kyuuryou * 2 - 50;

	return Recursive(nextKyuuryou, saikiSum + nextKyuuryou, zikan + 1, ippanSum + IPPAN_JIKYU);
}

int main() {
	//コンソールを UTF-8 にする設定
	system("chcp 65001 > nul");

	int saiki = 100;	//再帰的な賃金体系の最初の時給
	int zikan = 1;		//最初の1時間

	Recursive(saiki, saiki, zikan, IPPAN_JIKYU);

	return 0;
}