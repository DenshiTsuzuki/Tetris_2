#pragma once
#include"Common.h"
class End : public Task_Scene::Scene
{
private:
	Font _bigfont;
	Font _font;

	//�I�𒆁@�\���p
	int _targetNum;
	Point _targetPos[2];
	Rect _target;

public:
	//�R���X�g���N�^
	End(const InitData& init_);
	~End();
	//�X�V
	void update()override;
	//�`��@const�C��
	void draw()const override;

};


