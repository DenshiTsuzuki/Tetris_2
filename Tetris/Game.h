#pragma once
#include"Common.h"
#include"Mino.h"
#include"Field.h"
class Game : public Task_Scene::Scene
{
	Mino _mino;
	Field _field;
public:
	//�R���X�g���N�^
	Game(const InitData& init_);
	//�X�V
	void update()override;
	//�`��@const�C��
	void draw()const override;
	~Game();
};


