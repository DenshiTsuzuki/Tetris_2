#pragma once
#include"Common.h"
#include"Mino.h"
#include"Field.h"

class Game : public Task_Scene::Scene
{
	//�����~�m
	shared_ptr<Mino> _mino;

	//�t�B�[���h
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


