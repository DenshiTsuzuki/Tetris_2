#pragma once
#include"Common.h"
class Mino
{
public:
	//�ʒu
	Point _pos;

	//��]��
	int _r;

	//�ԍ�����U��
	Mino_Type _type;
	
	//�`
	int _shape[mino_wh][mino_wh];

	Mino(int x, int y, int r, Mino_Type type);

	//�`���`
	void CreateMino();

	//�`��
	void Draw()const;
};

