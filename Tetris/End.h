#pragma once
#include"Common.h"
class End : public Task_Scene::Scene
{
private:
	Font _bigfont;
	Font _font;

	//選択中　表示用
	int _targetNum;
	Point _targetPos[2];
	Rect _target;

public:
	//コンストラクタ
	End(const InitData& init_);
	~End();
	//更新
	void update()override;
	//描画　const修飾
	void draw()const override;

};


