#pragma once
#include"Common.h"
class End : public Task_Scene::Scene
{
private:
	

public:
	//コンストラクタ
	End(const InitData& init_);
	//更新
	void update()override;
	//描画　const修飾
	void draw()const override;

};


