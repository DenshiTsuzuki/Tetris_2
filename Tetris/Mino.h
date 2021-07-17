#pragma once
#include"Common.h"

class Field;
class Game;

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

	//落下インターバル
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

	//更新処理
	void Update(Game* game_,Field& field_);

private:
	//落ちる処理
	void Fall(Game* game_,Field& field_);

	//横移動処理
	void MoveLR(Field& field_);

	//回転処理
	void Rotation(Field& field_);

};
