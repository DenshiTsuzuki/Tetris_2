#pragma once
#include"Common.h"
class Mino
{
	//回転！
	void Rotate();
	
	//形状定義
	void CreateMino();

public:
	//タイマー
	int _fallcnt;

	//インターバル
	int _interval;

	//位置
	Point _pos;

	//回転数
	int _r;

	//番号割り振り
	Mino_Type _type;
	
	//形
	int _shape[mino_wh][mino_wh];

	Mino(int x, int y, int r, Mino_Type type);

	//描画
	void Draw()const;

	//更新
	void Update();
};

