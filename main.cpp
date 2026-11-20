#include <cstdio>
#include <cstdlib>

class Animal {
public:
    // 親クラスの仮想関数
    virtual void sound() const {
        printf("動物が鳴きます\n");
    }

    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    // 親クラスのsoundをオーバーライド
    void sound() const override {
        printf("イヌ鳴き声：ワン\n");
    }
};

class Cat : public Animal {
public:
    // 親クラスのsoundをオーバーライド
    void sound() const override {
        printf("ネコ鳴き声：ニャー\n");
    }
};

int main() {
    //コンソールを UTF-8 にする設定
    system("chcp 65001 > nul");

    Animal animal;
    Dog dog;
    Cat cat;

    // 親クラスのポインタで各オブジェクトを指す
    Animal* animal1 = &animal;
    Animal* animal2 = &dog;
    Animal* animal3 = &cat;

    // 指しているオブジェクトに応じたsoundが呼ばれる
    animal1->sound();
    animal2->sound();
    animal3->sound();

    return 0;
}