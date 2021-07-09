#pragma once
#include<Siv3D.hpp>
using namespace std;

enum class State {
	Title,
	Game,
	End
};

//シーン跨いで共有するもの
struct GameData {
	int HighScore = 0;
};

using Task_Scene = SceneManager < State, GameData >;

enum class Mino_Type :int{
	I = 2,
	O ,
	T ,
	J ,
	L ,
	S ,
	Z 
};

//プレイヤー保存
struct Player {
	String _name;
	int _level;
	int _score;
	Player() :
		_name(U"P1"), 
		_level(0),
		_score(0) 
	{

	}
};

//プレイヤー
static Player player;

//フィールド配列
#define field_size_x 12
#define field_size_y 21

//矩形サイズ
#define mino_s 25

//フィールド表示初期位置
#define field_x 40
#define field_y 60

//4*4
#define mino_wh 4

//落下時間初期値
#define def_interval 24