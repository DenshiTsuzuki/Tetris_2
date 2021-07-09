#include"Field.h"
Field::Field() :
	_field{//�t�B�[���h�z�񏉊���
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1 },
		}
{
	


}

Field::~Field()
{
}

bool Field::CheckHit(Mino* mino_)
{
	for (int y = 0;y < 4;++y) {
		for (int x = 0;x < 4;++x) {
			//���肵�Ȃ�
			if (mino_->_shape[y][x] == 0) { continue; }

			int xx = mino_->_pos.x + x;
			int yy = mino_->_pos.y + y;
			//�͈͊O�`�F�b�N
			if (xx < 0 || xx >= field_size_x 
				|| yy < 0 || yy >= field_size_y) {
				return true;
			}

			//�u���b�N���̃u���b�N�Ɠ������Ă���ꍇ
			if (this->_field[yy][xx] != 0) {
				return true;
			}

		}
	}
	return false;
}

void Field::InputMino(Mino* mino_)
{
	for (int y = 0;y < mino_wh;++y) {
		for (int x = 0;x < mino_wh;++x) {
			//0�͎�荞�܂Ȃ�
			if (mino_->_shape[y][x] == 0) { continue; }
		
			int xx = mino_->_pos.x + x;
			int yy = mino_->_pos.y + y;

			//��������
			this->_field[yy][xx] = mino_->_shape[y][x];
		}
	}
}

void Field::Draw() const
{
	//�z��ԍ��ɂ���Đ��l���킯��
	for (int y = 0;y < field_size_y;++y) {
		for (int x = 0;x < field_size_x;++x) {
			if (this->_field[y][x] == 0) { continue; }
			Rect(x * mino_s + field_x, y * mino_s + field_y, mino_s, mino_s).draw().drawFrame(0, 1, Palette::Black);
		}
	}
}
