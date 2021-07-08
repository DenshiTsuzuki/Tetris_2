#pragma once
#include"Common.h"
class Mino
{
public:
	//位置
	Point _pos;

	//回転数
	int _r;

	//番号割り振り
	Mino_Type _type;
	
	//形
	int _shape[mino_wh][mino_wh];

	Mino(int x, int y, int r, Mino_Type type);

	//形状定義
	void CreateMino();

	//描画
	void Draw()const;
};

