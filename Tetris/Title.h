#pragma once
#include"Common.h"
class Title: public Task_Scene::Scene
{
private:
	

public:
	//コンストラクタ
	Title(const InitData& init_);
	//更新
	void update()override;
	//描画　const修飾
	void draw()const override;

};


