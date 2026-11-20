#include <stdio.h>
#include <stdlib.h>

// 図形のインターフェイス
class IShape {
public:
	virtual void Size() = 0;	// 面積を求める
	virtual void Draw() = 0;	// 面積を表示する
	virtual ~IShape() = default;
};

// 円
class Circle : public IShape {
public:
	Circle(float radius) : radius(radius) {}

	void Size() override { area = radius * radius * 3.14f; }
	void Draw() override { printf("円の面積: %f\n", area); }

private:
	float radius;		// 半径
	float area = 0;		// 面積
};

// 矩形
class Rectangle : public IShape {
public:
	Rectangle(float width, float height) : width(width), height(height) {}

	void Size() override { area = width * height; }
	void Draw() override { printf("矩形の面積: %f\n", area); }

private:
	float width;		// 幅
	float height;		// 高さ
	float area = 0;		// 面積
};

int main() {
	//コンソールを UTF-8 にする設定
	system("chcp 65001 > nul");

	IShape* shapes[] = { new Circle(5.0f), new Rectangle(4.0f, 6.0f) };

	for (IShape* shape : shapes) {
		shape->Size();
		shape->Draw();
		delete shape;
	}

	return 0;
}