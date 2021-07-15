#pragma once
#include"Mino.h"
#include"Field.h"

class GameSystem
{
	GameSystem();
	~GameSystem();

	Font _font;
	Font _minifont;
public:
	//�~�m
	Mino::UP _mino;

	//��
	Mino::UP _nextmino;

	//�z�[���h
	Mino::UP _holdmino;

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

	//���݃n�C�X�R�A
	int _nowhighscore;

	void Update();

	void Draw()const;

	//�~�m�ύX�@�l�N�X�g���
	void ChangeMino();

	//�z�[���h�~�m�ύX
	void MinoHold();

	//�V���O���g��
	static GameSystem* gs1;
	static GameSystem* GetInstance();
	static void Create();
	static void Destroy();
};


