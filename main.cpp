#include <stdio.h>
#include <stdlib.h>

// 2つの値を比べて小さい値を返すクラステンプレート
template <typename T1, typename T2>
class Compare {
public:
	// メンバ変数
	T1 a;
	T2 b;

	// コンストラクタ
	Compare(T1 a, T2 b) : a(a), b(b) {}

	// メンバ関数 小さい値を返す
	T1 Min() {
		if (a > b) {
			return static_cast<T1>(b);
		} else {
			return static_cast<T1>(a);
		}
	}
};

int main() {
	//コンソールを UTF-8 にする設定
	system("chcp 65001 > nul");

	// 同じ型の組み合わせ(3パターン)
	Compare<int, int>       c1(128, 256);
	Compare<float, float>   c2(52.5f, 55.0f);
	Compare<double, double> c3(3.14159265, 2.7182818281);

	// 異なる型の組み合わせ(3C2 = 3パターン)
	Compare<float, int>     c4(10.5f, 7);
	Compare<double, int>    c5(1.41421356, 3);
	Compare<double, float>  c6(9.87654321, 1.5f);

	// 計算と結果出力
	printf("int     int    : %d\n", c1.Min());
	printf("float   float  : %f\n", c2.Min());
	printf("double  double : %lf\n", c3.Min());
	printf("float   int    : %f\n", c4.Min());
	printf("double  int    : %lf\n", c5.Min());
	printf("double  float  : %lf\n", c6.Min());

	return 0;
}