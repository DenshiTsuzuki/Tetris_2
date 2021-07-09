#pragma once
#include"Common.h"
class Mino
{
	//�E��]�I
	void RotateR();
	
	//����]�I
	void RotateL();
	//�`���`
	void CreateMino();

public:
	using SP = shared_ptr<Mino>;
	using WP = weak_ptr<Mino>;
	using UP = unique_ptr<Mino>;

	//�^�C�}�[
	int _fallcnt;
	int _movecnt;

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

	Mino(int x, int y, Mino_Type type);

	//�`��
	void Draw()const;

	//�X�V
	void Update();
};

