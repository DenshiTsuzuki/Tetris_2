#pragma once
#include"Common.h"

class Field {
	
	//�t�B�[���h
	int _field[field_size_y][field_size_x];
	
public:
	//�R���X�g���N�^�I
	Field();

	//�f�X�g���N�^�I
	~Field();

	//�t�B�[���h�`��
	void Draw()const;
};