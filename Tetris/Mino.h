#pragma once
#include"Common.h"
class Mino
{
	//��]�I
	void Rotate();
	
	//�`���`
	void CreateMino();

public:
	//�^�C�}�[
	int _fallcnt;

	//�C���^�[�o��
	int _interval;

	//�ʒu
	Point _pos;

	//��]��
	int _r;

	//�ԍ�����U��
	Mino_Type _type;
	
	//�`
	int _shape[mino_wh][mino_wh];

	Mino(int x, int y, int r, Mino_Type type);

	//�`��
	void Draw()const;

	//�X�V
	void Update();
};

