#include <iostream>

int main() {
	//コンソ ー ルを UTF -8 にする設定
	system("chcp 65001 > nul");
	char str[] = "ソ";

	printf("%s",str);

	return 0;
}