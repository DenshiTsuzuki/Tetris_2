#pragma once
#include"Common.h"
class Title: public Task_Scene::Scene
{
private:
	Font _titlefont;
	Font _font;

public:
	//�R���X�g���N�^
	Title(const InitData& init_);
	//�f�X�g���N�^�I
	~Title();

	//�X�V
	void update()override;
	//�`��@const�C��
	void draw()const override;

};


