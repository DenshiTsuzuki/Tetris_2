#pragma once
#include"Mino.h"
#include"Common.h"

class Field {
	
	//フィールド
	int _field[field_size_y][field_size_x];
	
public:
	//コンストラクタ！
	Field();

	//デストラクタ！
	~Field();

	//当たった判定
	bool CheckHit(Mino& mino_);

	//フィールド描画
	void Draw()const;
};
Field* field = nullptr;