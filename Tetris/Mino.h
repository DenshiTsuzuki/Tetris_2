#pragma once
#include"Common.h"
class Mino
{
public:
	//ˆÊ’u
	Point _pos;

	//‰ñ“]”
	int _r;

	//”Ô†Š„‚èU‚è
	Mino_Type _type;
	
	//Œ`
	int _shape[mino_wh][mino_wh];

	Mino(int x, int y, int r, Mino_Type type);

	//Œ`ó’è‹`
	void CreateMino();

	//•`‰æ
	void Draw()const;
};

