#pragma once
#include"Common.h"
class Game : public Task_Scene::Scene
{

public:
	//�R���X�g���N�^
	Game(const InitData& init_);
	//�X�V
	void update()override;
	//�`��@const�C��
	void draw()const override;

	~Game();
};


