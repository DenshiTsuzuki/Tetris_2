#pragma once
#include"Mino.h"
#include"Field.h"

class GameSystem
{
	GameSystem();
	~GameSystem();

	Font _font;
	Font _minifont;
public:
	//ミノ
	Mino::UP _mino;

	//次
	Mino::UP _nextmino;

	//フィールド
	Field::UP _field;

	//ゲームオーバー判定
	bool _isGameOver;

	//スコア
	int _score;

	//レベル落下速度変更
	int _level;

	//次のシーンいくまでのdelay
	int _fadecnt;

	//現在ハイスコア
	int _nowhighscore;

	void Update();

	void Draw()const;

	//シングルトン
	static GameSystem* gs1;
	static GameSystem* GetInstance();
	static void Create();
	static void Destroy();
};


