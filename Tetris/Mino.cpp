#pragma once
#include"Mino.h"
#include"GameSystem.h"

Mino::Mino(int x, int y, Mino_Type type) :
	_fallcnt(0),
	_interval(def_interval),
	_pos(x, y),
	_type(type),
	_rot(0),
	_movecnt(10),
	_rotcnt(10)
{

};

void Mino::Draw(int x_, int y_) const
{
	BlockData* _bd = &bdp[(int)this->_type][this->_rot];
	for (int y = 0;y < 4;++y) {
		for (int x = 0;x < 4;++x) {
			if (_bd->_arr[y][x] == 0) { continue; }

			TextureAsset(U"Block")((int)this->_type * 12, 0, 12, 12)
				.resized(mino_s)
				.draw((this->_pos.x + x) * mino_s + x_, (this->_pos.y + y) * mino_s + y_);
		}
	}
}

void Mino::DrawWithGrid(int x_, int y_) const
{
	BlockData* _bd = &bdp[(int)this->_type][this->_rot];
	for (int y = 0;y < 4;++y) {
		for (int x = 0;x < 4;++x) {
			//�t�B�[���h�̃O���b�h���`��
			Rect((this->_pos.x + x) * mino_s + x_,
				(this->_pos.y + y) * mino_s + y_, mino_s, mino_s).drawFrame(0, 1, Palette::Whitesmoke);

			if (_bd->_arr[y][x] == 0) { continue; }

			TextureAsset(U"Block")((int)this->_type * 12, 0, 12, 12)
				.resized(mino_s)
				.draw((this->_pos.x + x) * mino_s + x_, (this->_pos.y + y) * mino_s + y_);
		}
	}
}

void Mino::Update()
{
	++_fallcnt;
	++_movecnt;
	++_rotcnt;

	//�����擾�p
	GameSystem* gm = GameSystem::GetInstance();
	
	//�t�B�[���h���擾
	auto& field = gm->_field;
	
	//��������
	if (this->_fallcnt >= this->_interval || KeyDown.pressed()) {
		++this->_pos.y;
		this->_fallcnt = 0;
		//�����蔻��
		if (field->CheckHit(&this->_pos, &bdp[(int)this->_type][this->_rot])) {
		//���ɍs���Ȃ�
		--this->_pos.y;

		//�t�B�[���h�ɏ�������
		field->InputMino(&this->_pos,&bdp[(int)this->_type][this->_rot]);

		//�Ֆʏ���������s��
		int i = field->Erase();

		//���_���Z
		gm->_score += scoredef[i];

		//�폜
		gm->_mino.release();

		
		}
	}


	//-----------------------���ւ̈ړ�------------------------------------------------
	int preX = this->_pos.x;

	//���ړ��I
	if (KeyLeft.pressed() && _movecnt > 10) { 
		--this->_pos.x; 
		_movecnt = 0;
	}
	//�E�ړ��I
	if (KeyRight.pressed() && _movecnt > 10) { 
		++this->_pos.x; 
		_movecnt = 0; 
	}
	if (field->CheckHit(&this->_pos, &bdp[(int)this->_type][this->_rot])) {
		this->_pos.x = preX;
	}


	//----------------------��]����---------------------------------------------------
	int prerot = this->_rot;
	//�E��]�I
	if (KeyZ.pressed() && _rotcnt > 10) {
		//��
		AudioAsset(U"Rot").playOneShot();

		this->_rot = (this->_rot + 1 + 50000) % 4;
		_rotcnt = 0;
	}
	//����]�I
	if (KeyX.pressed() && _rotcnt > 10) { 
		//��
		AudioAsset(U"Rot").playOneShot();

		this->_rot = (this->_rot - 1 + 50000) % 4;
		_rotcnt = 0;
	}
	//�ڐG����
	if (field->CheckHit(&this->_pos, &bdp[(int)this->_type][this->_rot])) {
		this->_rot = prerot;
	}


}

