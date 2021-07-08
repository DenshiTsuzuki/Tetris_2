#pragma once
#include"Common.h"
#include"Mino.h"
#include"Field.h"
class Game : public Task_Scene::Scene
{
	Mino _mino;
	Field _field;
public:
	//コンストラクタ
	Game(const InitData& init_);
	//更新
	void update()override;
	//描画　const修飾
	void draw()const override;
	~Game();
};


