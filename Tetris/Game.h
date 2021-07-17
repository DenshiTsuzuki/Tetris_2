#pragma once
#include"Common.h"
#include"Mino.h"
#include"Field.h"

class Game : public Task_Scene::Scene
{
	//�����\���p�t�H���g
	Font _font;
	Font _minifont;

	//���݃n�C�X�R�A
	int _nowhighscore;

	//�~�m
	Mino::UP _mino;

	//��
	Mino::UP _nextmino;

	//�z�[���h
	Mino::UP _holdmino;
	bool _isHold;

	//�t�B�[���h
	Field::UP _field;

	//�Q�[���I�[�o�[����
	bool _isGameOver;

	//�X�R�A
	int _score;

	//���x���������x�ύX
	int _level;

	//���̃V�[�������܂ł�delay
	int _fadecnt;
public:
	//�X�R�A��������
	void ScorePuls(int i_);

private:
	//�t�F�[�h�p f_�b��t�F�[�h
	void Fade(int f_);

	//�~�m�ύX�@�l�N�X�g���
	void ChangeMino();

	//�z�[���h�~�m�ύX
	void MinoHold();

public:
	//�R���X�g���N�^
	Game(const InitData& init_);

	//�f�X�g���N�^
	~Game();

	//�X�V
	void update()override;

	//�`��@const�C��
	void draw()const override;


};


