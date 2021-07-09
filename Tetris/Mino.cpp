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
	//右回転
	for (int y = 0;y < 2;++y) {
		for (int x = 0;x < 2;++x) {
			//番号保存
			int tmp = this->_shape[3 - x][y];

			//左下に右下を代入
			this->_shape[3 - x][y] = this->_shape[3 - y][3 - x];

			//右下に右上を代入
			this->_shape[3 - y][3 - x] = this->_shape[x][3 - y];

			//右上に左上を
			this->_shape[x ][3 - y] = this->_shape[y][x];

			this->_shape[y][x] = tmp;
		}
	}
}

void Mino::RotateL()
{
	//左回転
	for (int y = 0;y < 2;++y) {
		for (int x = 0;x < 2;++x) {
			//左上保存
			int tmp = this->_shape[y][x];

			//右上を左上へ
			this->_shape[y][x] = this->_shape[x][3 - y];

			//右下を右上へ
			this->_shape[x][3 - y] = this->_shape[3 - y][3 - x];

			//左下を右下へ
			this->_shape[3 - y][3 - x] = this->_shape[3 - x][y];

			//保存していたものを左下へ
			this->_shape[3 - x][y] = tmp;
		}
	}
}

void Mino::CreateMino()
{
	
	//形状を決める
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
	//落下処理
	if (this->_fallcnt >= this->_interval || KeyDown.pressed()) {
		++this->_pos.y;
		this->_fallcnt = 0;
		//当たっている判定
		if (field->CheckHit(this)) {
			//下に行かない
			--this->_pos.y;

			//フィールドに書き込み
			field->InputMino(this);

			//削除
			GameSystem::GetInstance()->_mino.release();
		}
	}
	//横への移動
	Point pre = this->_pos;
	if (KeyLeft.pressed() && _movecnt > 15) { --this->_pos.x; _movecnt = 0; }
	if (KeyRight.pressed() && _movecnt > 15) { ++this->_pos.x; _movecnt = 0; }
	if (field->CheckHit(this)) {
		this->_pos = pre;
	}

	//回転処理
	//開店前を保存
	int pre2[4][4];
	memcpy(pre2,this->_shape, sizeof(this->_shape));
	
	//右回転
	if (KeyZ.down()) {
		this->RotateR();
	}

	//左回転
	if (KeyX.down()) {
		this->RotateL();
	}

	//戻す
	if (field->CheckHit(this)) {
		memcpy(this->_shape, pre2, sizeof(this->_shape));
	}
}

