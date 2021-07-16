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
			//フィールドのグリッド線描画
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

	//譲歩取得用
	GameSystem* gm = GameSystem::GetInstance();
	
	//フィールド情報取得
	auto& field = gm->_field;
	
	//落下処理
	if (this->_fallcnt >= this->_interval || KeyDown.pressed()) {
		++this->_pos.y;
		this->_fallcnt = 0;
		//当たり判定
		if (field->CheckHit(&this->_pos, &bdp[(int)this->_type][this->_rot])) {
		//下に行かない
		--this->_pos.y;

		//フィールドに書き込み
		field->InputMino(&this->_pos,&bdp[(int)this->_type][this->_rot]);

		//盤面消去判定を行う
		int i = field->Erase();

		//得点加算
		gm->_score += scoredef[i];

		//削除
		gm->_mino.release();

		
		}
	}


	//-----------------------横への移動------------------------------------------------
	int preX = this->_pos.x;

	//左移動！
	if (KeyLeft.pressed() && _movecnt > 10) { 
		--this->_pos.x; 
		_movecnt = 0;
	}
	//右移動！
	if (KeyRight.pressed() && _movecnt > 10) { 
		++this->_pos.x; 
		_movecnt = 0; 
	}
	if (field->CheckHit(&this->_pos, &bdp[(int)this->_type][this->_rot])) {
		this->_pos.x = preX;
	}


	//----------------------回転処理---------------------------------------------------
	int prerot = this->_rot;
	//右回転！
	if (KeyZ.pressed() && _rotcnt > 10) {
		//音
		AudioAsset(U"Rot").playOneShot();

		this->_rot = (this->_rot + 1 + 50000) % 4;
		_rotcnt = 0;
	}
	//左回転！
	if (KeyX.pressed() && _rotcnt > 10) { 
		//音
		AudioAsset(U"Rot").playOneShot();

		this->_rot = (this->_rot - 1 + 50000) % 4;
		_rotcnt = 0;
	}
	//接触判定
	if (field->CheckHit(&this->_pos, &bdp[(int)this->_type][this->_rot])) {
		this->_rot = prerot;
	}


}

