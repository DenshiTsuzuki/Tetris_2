#pragma once
#include"Common.h"

class Mino
{

public:
	using SP = shared_ptr<Mino>;
	using WP = weak_ptr<Mino>;
	using UP = unique_ptr<Mino>;
	//�^�C�}�[	//���ړ�,���ړ�,��]
	int _fallcnt;
	int _movecnt;
	int _rotcnt;

	//�C���^�[�o��
	int _interval;

	//�ʒu
	Point _pos;

	//��]��
	int _rot;

	//�ԍ�����U��
	Mino_Type _type;

	Mino(int x, int y, Mino_Type type);

	//�I�t�Z�b�g�Ή�Draw
	void Draw(int x_, int y_)const;

	//�O���b�h���ݕ\��
	void DrawWithGrid(int x_, int y_)const;

	//�X�V
	void Update();
};
