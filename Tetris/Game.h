#pragma once
#include"Common.h"
#include"Mino.h"
#include"Field.h"

class Game : public Task_Scene::Scene
{
	//文字表示用フォント
	Font _font;
	Font _minifont;

	//現在ハイスコア
	int _nowhighscore;

	//ミノ
	Mino::UP _mino;

	//次
	Mino::UP _nextmino;

	//ホールド
	Mino::UP _holdmino;
	bool _isHold;

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
public:
	//スコア足すだけ
	void ScorePuls(int i_);

private:
	//フェード用 f_秒後フェード
	void Fade(int f_);

	//ミノ変更　ネクストより
	void ChangeMino();

	//ホールドミノ変更
	void MinoHold();

public:
	//コンストラクタ
	Game(const InitData& init_);

	//デストラクタ
	~Game();

	//更新
	void update()override;

	//描画　const修飾
	void draw()const override;


};


