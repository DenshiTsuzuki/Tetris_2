#pragma once
#include"Common.h"
class End : public Task_Scene::Scene
{
private:
	

public:
	//�R���X�g���N�^
	End(const InitData& init_);
	//�X�V
	void update()override;
	//�`��@const�C��
	void draw()const override;

};


