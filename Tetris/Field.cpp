#include"Field.h"
Field::Field() :
	_field{//�t�B�[���h�z�񏉊���
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0 }
		}
{
	


}

Field::~Field()
{
}

bool Field::CheckHit(Point* p_, BlockData* b_)
{
	for (int y = 0;y < 4;++y) {
		for (int x = 0;x < 4;++x) {
			//���肵�Ȃ�
			if (b_->_arr[y][x] == 0) { continue; }
			
			int xx = p_->x + x;
			int yy = p_->y + y;

			//�͈͊O�`�F�b�N
			if (xx < 0 || xx >= field_size_x || yy < 0 || yy >= field_size_y) {
				return true;
			}

			//�u���b�N�Ƃ̓����蔻��
			if (this->_field[yy][xx] != 0) {
				return true;
			}
		}
	}

	return false;
}

void Field::InputMino(Point* p_, BlockData* b_)
{
	//��
	AudioAsset(U"MinoInput").playOneShot();

	for (int y = 0;y < 4;++y) {
		for (int x = 0;x < 4;++x) {
			//0 �͔��肵�Ȃ�
			if (b_->_arr[y][x] == 0) { continue; }

			int xx = p_->x + x;
			int yy = p_->y + y;

			//��������
			this->_field[yy][xx] = b_->_arr[y][x];
		}
	}
}

int Field::Erase()
{
	//�������s�����J�E���g
	int erasecnt = 0;

	
	//�S�s���@�����p��4�s�͔�����s��Ȃ�
	bool erase_arr[field_size_y] = { false,false,false,false,true ,true,true ,true, true ,true, true ,true, true ,true, true ,true, true ,true, true ,true, true ,true, true ,true,true};

	//������ꏊ�m�F
	for (int y = field_begin; y < field_size_y ;++y) {
		for (int x = 0;x < field_size_x ;++x) {
			//0��������������Ȃ��s�ł���
			if (this->_field[y][x] == 0) {
				erase_arr[y] = false;
				break;
			}
		}
	}

	//���������@true�s���폜�@0�����
	for (int y = field_begin;y < field_size_y ;++y) {
		//�폜�\
		if (erase_arr[y] == true) {
			++erasecnt;
			for (int x = 0;x < field_size_x;++x) {
				this->_field[y][x] = 0;
			}
		}
	}

	//���ɋl�߂�
	if (erasecnt > 0) {
		int tmp[field_size_y][field_size_x] = { 0 };

		//������R�s�[���s��
		int yy = field_size_y - 1;

		//�t�B�[���h�������猩�Ă���
		for (int y = field_size_y - 1;y > field_begin;--y) {
			//�폜�����������݂�����R�s�[���Ȃ�
			if (erase_arr[y] == true) {
				continue;
			}
			memcpy(tmp[yy], _field[y], sizeof(tmp[y]));
			--yy;
		}

		memcpy(this->_field, tmp, sizeof(tmp));
	}
	//�������s�����̃J�E���g��Ԃ�
	return erasecnt;
}

void Field::Draw() const
{
	//�z��ԍ��ɂ���Đ��l���킯��
	for (int y = field_begin;y < field_size_y;++y) {
		for (int x = 0;x < field_size_x;++x) {
			//�t�B�[���h�̃O���b�h���`��
			Rect(x * mino_s + field_x, y * mino_s + field_y, mino_s, mino_s).drawFrame(0, 1, Palette::Whitesmoke);

			//�u���b�N�̕`��
			if (this->_field[y][x] == 0) { continue; }


			TextureAsset(U"Block")(this->_field[y][x] * 12, 0, 12, 12)
				.resized(mino_s)
				.draw(x * mino_s + field_x, y * mino_s + field_y);
		}
	}
}
