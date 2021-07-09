#include"Mino.h"
Mino::Mino(int x, int y, int r, Mino_Type type) :
	_fallcnt(0),
	_interval(def_interval - player._level * 2),
	_pos(x, y),
	_r(r),
	_type(type),
	_shape{
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
}
{
	this->CreateMino();
};
void Mino::Rotate()
{
	
}
void Mino::CreateMino()
{
	
	//Œ`ó‚ğŒˆ‚ß‚é
	switch (this->_type) {
		using enum Mino_Type;
	case I:
		_shape[0][1] = int(I);
		_shape[1][1] = int(I);
		_shape[2][1] = int(I);
		_shape[3][1] = int(I);
		break;

	case T:
		_shape[0][1] = int(T);
		_shape[1][0] = int(T);
		_shape[1][1] = int(T);
		_shape[1][2] = int(T);
		break;

	case O:
		_shape[1][1] = int(O);
		_shape[1][2] = int(O);
		_shape[2][1] = int(O);
		_shape[2][2] = int(O);
	break;

	case J:
		_shape[0][1] = int(J);
		_shape[1][1] = int(J);
		_shape[2][0] = int(J);
		_shape[2][1] = int(J);
		break;

	case L:
		_shape[0][0] = int(L);
		_shape[1][0] = int(L);
		_shape[2][0] = int(L);
		_shape[2][1] = int(L);
		break;

	case S:
		_shape[0][1] = int(S);
		_shape[0][2] = int(S);
		_shape[1][1] = int(S);
		_shape[1][0] = int(S);
		break;

	case Z:
		_shape[0][0] = int(Z);
		_shape[0][1] = int(Z);
		_shape[1][1] = int(Z);
		_shape[1][2] = int(Z);
		break;
	}

}

void Mino::Draw() const
{
	for (int y = 0;y < mino_wh;++y) {
		for (int x = 0;x < mino_wh;++x) {
			if (this->_shape[y][x] == 0) { continue; }
			
			Rect((this->_pos.x + x) * mino_s + field_x, 
				(this->_pos.y + y) * mino_s + field_y, mino_s, mino_s).draw().drawFrame(0, 1, Palette::Black);
		}
	}

}

void Mino::Update()
{
	++_fallcnt;
	//—‰ºˆ—
	if (this->_fallcnt >= this->_interval || KeyDown.pressed()) {
		++this->_pos.y;
		this->_fallcnt = 0;

	}
}
