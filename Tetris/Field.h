#pragma once
#include"Common.h"

class Field {
	
	//フィールド
	int _field[field_size_y][field_size_x];
	
public:
	//コンストラクタ！
	Field();

	//デストラクタ！
	~Field();

	//フィールド描画
	void Draw()const;
};