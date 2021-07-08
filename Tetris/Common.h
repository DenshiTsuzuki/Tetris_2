#pragma once
#include<Siv3D.hpp>

enum class State {
	Title,
	Game,
	End
};

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

//マクロ定義
#define field_size_x 12
#define field_size_y 21

//矩形サイズ
#define mino_s 25

//フィールド表示初期位置
#define field_x 40
#define field_y 60

#define mino_wh 4