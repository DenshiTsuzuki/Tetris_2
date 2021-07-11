#pragma once
#include"Common.h"

class Mino
{

public:
	using SP = shared_ptr<Mino>;
	using WP = weak_ptr<Mino>;
	using UP = unique_ptr<Mino>;
	//タイマー	//下移動,横移動,回転
	int _fallcnt;
	int _movecnt;
	int _rotcnt;

	//インターバル
	int _interval;

	//位置
	Point _pos;

	//回転数
	int _rot;

	//番号割り振り
	Mino_Type _type;

	Mino(int x, int y, Mino_Type type);

	//オフセット対応Draw
	void Draw(int x_, int y_)const;

	//グリッド込み表示
	void DrawWithGrid(int x_, int y_)const;

	//更新
	void Update();
};
