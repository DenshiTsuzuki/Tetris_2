#include"Field.h"
Field::Field() :
	_field{//フィールド配列初期化
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 }
		}
{
	


}

Field::~Field()
{
}

bool Field::CheckHit(Point* p_, BlockData* b_)
{
	for (int y = 0;y < 4;++y) {
		for (int x = 0;x < 4;++x) {
			//判定しない
			if (b_->_arr[y][x] == 0) { continue; }
			
			int xx = p_->x + x;
			int yy = p_->y + y;

			//範囲外チェック
			if (xx < 0 || xx >= field_size_x || yy < 0 || yy >= field_size_y) {
				return true;
			}

			//ブロックとの当たり判定
			if (this->_field[yy][xx] != 0) {
				return true;
			}
		}
	}

	return false;
}

void Field::InputMino(Point* p_, BlockData* b_)
{
	//音
	AudioAsset(U"MinoInput").playOneShot();

	for (int y = 0;y < 4;++y) {
		for (int x = 0;x < 4;++x) {
			//0 は判定しない
			if (b_->_arr[y][x] == 0) { continue; }

			int xx = p_->x + x;
			int yy = p_->y + y;

			//書き込み
			this->_field[yy][xx] = b_->_arr[y][x];
		}
	}
}

int Field::Erase()
{
	//消した行数分カウント
	int erasecnt = 0;

	
	//全行文　生成用の4行は判定を行わない
	bool erase_arr[field_size_y] = { false,false,false,false,true ,true,true ,true, true ,true, true ,true, true ,true, true ,true, true ,true, true ,true, true ,true, true ,true,true};

	//消せる場所確認
	for (int y = field_begin; y < field_size_y ;++y) {
		for (int x = 0;x < field_size_x ;++x) {
			//0を見つけたら消せない行である
			if (this->_field[y][x] == 0) {
				erase_arr[y] = false;
				break;
			}
		}
	}

	//消去処理　true行を削除　0入れる
	for (int y = field_begin;y < field_size_y ;++y) {
		//削除可能
		if (erase_arr[y] == true) {
			++erasecnt;
			for (int x = 0;x < field_size_x;++x) {
				this->_field[y][x] = 0;
			}
		}
	}

	//下に詰める
	if (erasecnt > 0) {
		int tmp[field_size_y][field_size_x] = { 0 };

		//下からコピーを行う
		int yy = field_size_y - 1;

		//フィールドを下から見ていく
		for (int y = field_size_y - 1;y > field_begin;--y) {
			//削除した部分をみつけたらコピーしない
			if (erase_arr[y] == true) {
				continue;
			}
			memcpy(tmp[yy], _field[y], sizeof(tmp[y]));
			--yy;
		}

		memcpy(this->_field, tmp, sizeof(tmp));
	}
	//消した行数分のカウントを返す
	return erasecnt;
}

void Field::Draw() const
{
	//配列番号によって数値をわける
	for (int y = field_begin;y < field_size_y;++y) {
		for (int x = 0;x < field_size_x;++x) {
			//フィールドのグリッド線描画
			Rect(x * mino_s + field_x, y * mino_s + field_y, mino_s, mino_s).drawFrame(0, 1, Palette::Whitesmoke);

			//ブロックの描画
			if (this->_field[y][x] == 0) { continue; }


			TextureAsset(U"Block")(this->_field[y][x] * 12, 0, 12, 12)
				.resized(mino_s)
				.draw(x * mino_s + field_x, y * mino_s + field_y);
		}
	}
}
