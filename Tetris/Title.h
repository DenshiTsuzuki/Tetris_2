#pragma once
#include"Common.h"
class Title: public Task_Scene::Scene
{
private:
	

public:
	//�R���X�g���N�^
	Title(const InitData& init_);
	//�X�V
	void update()override;
	//�`��@const�C��
	void draw()const override;

};


