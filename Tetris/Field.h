#pragma once
#include"Mino.h"
#include"Common.h"

class Field {
public:

using SP = shared_ptr<Field>;
using WP = weak_ptr<Field>;
using UP = unique_ptr<Field>;
	//フィールド
	int _field[field_size_y][field_size_x];

	//コンストラクタ！
	Field();

	//デストラクタ！
	~Field();

	//当たった判定
	bool CheckHit(Mino* mino_);

	//ミノを取得して書き込む
	void InputMino(Mino* mino_);

	//フィールド描画
	void Draw()const;
};
