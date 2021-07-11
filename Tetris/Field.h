#pragma once
#include"Mino.h"
#include"Common.h"

class Field {
public:
//������������
using SP = shared_ptr<Field>;
using WP = weak_ptr<Field>;
using UP = unique_ptr<Field>;

	//�t�B�[���h
	int _field[field_size_y][field_size_x];

	//�R���X�g���N�^�I
	Field();

	//�f�X�g���N�^�I
	~Field();

	//������������
	bool CheckHit(Point* p_,BlockData* b_);

	//�~�m���擾���ď�������
	void InputMino(Point* p_,BlockData* b_);

	//�폜�����폜�����s����Ԃ�
	int Erase();
	
	//�t�B�[���h�`��
	void Draw()const;
};
