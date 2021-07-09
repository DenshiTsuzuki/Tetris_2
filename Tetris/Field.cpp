#include"Field.h"
Field::Field() :
	_field{//フィールド配列初期化
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
		}
{
	


}

Field::~Field()
{
}

bool Field::CheckHit(Mino* mino_)
{
	for (int y = 0;y < 4;++y) {
		for (int x = 0;x < 4;++x) {
			//判定しない
			if (mino_->_shape[y][x] == 0) { continue; }

			int xx = mino_->_pos.x + x;
			int yy = mino_->_pos.y + y;
			//範囲外チェック
			if (xx < 0 || xx >= field_size_x 
				|| yy < 0 || yy >= field_size_y) {
				return true;
			}

			//ブロック内のブロックと当たっている場合
			if (this->_field[yy][xx] != 0) {
				return true;
			}

		}
	}
	return false;
}

void Field::InputMino(Mino* mino_)
{
	for (int y = 0;y < mino_wh;++y) {
		for (int x = 0;x < mino_wh;++x) {
			//0は取り込まない
			if (mino_->_shape[y][x] == 0) { continue; }
		
			int xx = mino_->_pos.x + x;
			int yy = mino_->_pos.y + y;

			//書き込み
			this->_field[yy][xx] = mino_->_shape[y][x];
		}
	}
}

void Field::Draw() const
{
	//配列番号によって数値をわける
	for (int y = 0;y < field_size_y;++y) {
		for (int x = 0;x < field_size_x;++x) {
			if (this->_field[y][x] == 0) { continue; }
			Rect(x * mino_s + field_x, y * mino_s + field_y, mino_s, mino_s).draw().drawFrame(0, 1, Palette::Black);
		}
	}
}
