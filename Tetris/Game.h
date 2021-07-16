#pragma once
#include"Common.h"
class Game : public Task_Scene::Scene
{

public:
	//コンストラクタ
	Game(const InitData& init_);

	//フェード用
	void Fade();

	//更新
	void update()override;
	//描画　const修飾
	void draw()const override;

	~Game();
};


