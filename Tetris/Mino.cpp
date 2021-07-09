#pragma once
#include"Mino.h"
#include"GameSystem.h"

Mino::Mino(int x, int y, Mino_Type type) :
	_fallcnt(0),
	_interval(def_interval),
	_pos(x, y),
	_type(type),
	_movecnt(0),
	_shape{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	}
{
	this->CreateMino();
};
void Mino::RotateR()
{
	//�E��]
	for (int y = 0;y < 2;++y) {
		for (int x = 0;x < 2;++x) {
			//�ԍ��ۑ�
			int tmp = this->_shape[3 - x][y];

			//�����ɉE������
			this->_shape[3 - x][y] = this->_shape[3 - y][3 - x];

			//�E���ɉE�����
			this->_shape[3 - y][3 - x] = this->_shape[x][3 - y];

			//�E��ɍ����
			this->_shape[x ][3 - y] = this->_shape[y][x];

			this->_shape[y][x] = tmp;
		}
	}
}

void Mino::RotateL()
{
	//����]
	for (int y = 0;y < 2;++y) {
		for (int x = 0;x < 2;++x) {
			//����ۑ�
			int tmp = this->_shape[y][x];

			//�E��������
			this->_shape[y][x] = this->_shape[x][3 - y];

			//�E�����E���
			this->_shape[x][3 - y] = this->_shape[3 - y][3 - x];

			//�������E����
			this->_shape[3 - y][3 - x] = this->_shape[3 - x][y];

			//�ۑ����Ă������̂�������
			this->_shape[3 - x][y] = tmp;
		}
	}
}

void Mino::CreateMino()
{
	
	//�`������߂�
	switch (this->_type) {
		using enum Mino_Type;
	case I:
		_shape[0][1] = int(I);
		_shape[1][1] = int(I);
		_shape[2][1] = int(I);
		_shape[3][1] = int(I);
		break;

	case T:
		_shape[0][1] = int(T);
		_shape[1][0] = int(T);
		_shape[1][1] = int(T);
		_shape[1][2] = int(T);
		break;

	case O:
		_shape[1][1] = int(O);
		_shape[1][2] = int(O);
		_shape[2][1] = int(O);
		_shape[2][2] = int(O);
	break;

	case J:
		_shape[0][1] = int(J);
		_shape[1][1] = int(J);
		_shape[2][0] = int(J);
		_shape[2][1] = int(J);
		break;

	case L:
		_shape[0][0] = int(L);
		_shape[1][0] = int(L);
		_shape[2][0] = int(L);
		_shape[2][1] = int(L);
		break;

	case S:
		_shape[0][1] = int(S);
		_shape[0][2] = int(S);
		_shape[1][1] = int(S);
		_shape[1][0] = int(S);
		break;

	case Z:
		_shape[0][0] = int(Z);
		_shape[0][1] = int(Z);
		_shape[1][1] = int(Z);
		_shape[1][2] = int(Z);
		break;
	}

}

void Mino::Draw() const
{
	for (int y = 0;y < mino_wh;++y) {
		for (int x = 0;x < mino_wh;++x) {
			if (this->_shape[y][x] == 0) { continue; }
			
			Rect((this->_pos.x + x) * mino_s + field_x, 
				(this->_pos.y + y) * mino_s + field_y, mino_s, mino_s).draw().drawFrame(0, 1, Palette::Black);
		}
	}

}

void Mino::Update()
{
	++_fallcnt;
	++_movecnt;
	auto& field = GameSystem::GetInstance()->_field;
	//��������
	if (this->_fallcnt >= this->_interval || KeyDown.pressed()) {
		++this->_pos.y;
		this->_fallcnt = 0;
		//�������Ă��锻��
		if (field->CheckHit(this)) {
			//���ɍs���Ȃ�
			--this->_pos.y;

			//�t�B�[���h�ɏ�������
			field->InputMino(this);

			//�폜
			GameSystem::GetInstance()->_mino.release();
		}
	}
	//���ւ̈ړ�
	Point pre = this->_pos;
	if (KeyLeft.pressed() && _movecnt > 15) { --this->_pos.x; _movecnt = 0; }
	if (KeyRight.pressed() && _movecnt > 15) { ++this->_pos.x; _movecnt = 0; }
	if (field->CheckHit(this)) {
		this->_pos = pre;
	}

	//��]����
	//�J�X�O��ۑ�
	int pre2[4][4];
	memcpy(pre2,this->_shape, sizeof(this->_shape));
	
	//�E��]
	if (KeyZ.down()) {
		this->RotateR();
	}

	//����]
	if (KeyX.down()) {
		this->RotateL();
	}

	//�߂�
	if (field->CheckHit(this)) {
		memcpy(this->_shape, pre2, sizeof(this->_shape));
	}
}

