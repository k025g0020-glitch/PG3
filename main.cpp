#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <iostream>

using namespace std;

int main(void) {
	//コンソールを UTF-8 にする設定
	system("chcp 65001 > nul");

	//初めは1970年の駅名リスト
	list<const char*> eki_list{
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani", "Nippori", "Tabata", "Komagome", "Sugamo",
		"Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi", "Harajuku", "Shibuya", "Ebisu",
		"Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi", "Hamamatsucho", "Shimbashi", "Yurakucho"
	};

	printf("1970年\n");
	for (list<const char*>::iterator it_f = eki_list.begin(); it_f != eki_list.end(); it_f++) {
		std::cout << *it_f << endl;
	}

	printf("\n2019年\n");
	list<const char*>::iterator it_f;
	for (it_f = eki_list.begin(); it_f != eki_list.end(); ++it_f) {
		//田端駅の前(日暮里と田端の間)に西日暮里駅を挿入
		if (strcmp(*it_f, "Tabata") == 0) {
			it_f = eki_list.insert(it_f, "Nishi-Nippori");
			std::cout << *it_f << endl;
			++it_f;
		}
		std::cout << *it_f << endl;
	}

	printf("\n2022年\n");
	for (it_f = eki_list.begin(); it_f != eki_list.end(); ++it_f) {
		//田町駅の前(品川と田町の間)に高輪ゲートウェイ駅を挿入
		if (strcmp(*it_f, "Tamachi") == 0) {
			it_f = eki_list.insert(it_f, "Takanawa Gateway");
			std::cout << *it_f << endl;
			++it_f;
		}
		std::cout << *it_f << endl;
	}

	return 0;
}