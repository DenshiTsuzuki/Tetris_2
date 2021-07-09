#pragma once
#include"Common.h"
class Mino
{
	//右回転！
	void RotateR();
	
	//左回転！
	void RotateL();
	//形状定義
	void CreateMino();

public:
	using SP = shared_ptr<Mino>;
	using WP = weak_ptr<Mino>;
	using UP = unique_ptr<Mino>;

	//タイマー
	int _fallcnt;
	int _movecnt;

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

	Mino(int x, int y, Mino_Type type);

	//描画
	void Draw()const;

	//更新
	void Update();
};

