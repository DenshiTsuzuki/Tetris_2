#include "GameSystem.h"
GameSystem* GameSystem::gs1 = nullptr;

GameSystem::GameSystem() :
	_mino(make_unique<Mino>(4, 0, Mino_Type::O)),
	_nextmino(make_unique<Mino>(4,0, Mino_Type::T)),
	_field(make_unique<Field>()),
	_isGameOver(false),
	_fadecnt(9),
	_score(0),
	_level(1),
	_nowhighscore(0),
	_font(40,U"example/font/AnnyantRoman/AnnyantRoman.ttf"),
	_minifont(20, U"example/font/AnnyantRoman/AnnyantRoman.ttf")

{
	{
		TextReader reader(U"gamedata/score.txt");
		if (!reader) {
			throw Error(U"�X�R�A�t�@�C��������܂���");
		}
		String line;
		//��s�ڂ�ǂݍ���
		reader.readLine(line);
		this->_nowhighscore = Parse<int>(line);
	}
}
GameSystem::~GameSystem() {
	_mino.reset();
	_nextmino.reset();
	_field.reset();
}

void GameSystem::Update() {
	//�Q�[���I�[�o�[�Ȃ炱��ȍ~�̏������s��Ȃ�
	if (_isGameOver == true) {
		++this->_fadecnt;
		return;
	}

	//�Ֆʂő���ł���~�m�̃A�b�v�f�[�g���s
	if (this->_mino != nullptr) {
		this->_mino->Update();
	}

	//���삷��~�m��ύX
	if (this->_mino == nullptr && this->_nextmino != nullptr) {
		//�ύX��fallinterval��ύX����
		this->_nextmino->_interval -= this->_level - 1;
		this->_mino.swap(_nextmino);

		//�~�m�������ڐG���肪����΃Q�[���I�[�o�[
		this->_isGameOver = this->_field->CheckHit(&_mino->_pos, &bdp[(int)_mino->_type][_mino->_rot]);
	}
	
	//�l�N�X�g�~�m����
	if (this->_nextmino == nullptr) {
		int i = Random(1, 7);
		_nextmino = make_unique<Mino>(4, 0, Mino_Type(i));

	}

	//���x���̕ύX
	this->_level = 1 +  this->_score / 1000;
}

void GameSystem::Draw() const
{
	
	this->_field->Draw();
	
	if (this->_mino != nullptr) {
		this->_mino->Draw(field_x,field_y);
	}

	if (this->_nextmino != nullptr) {
		this->_nextmino->DrawWithGrid(next_x,next_y);
	}
	this->_font(U"SCORE : {}"_fmt(this->_score)).draw(score_x,score_y);
	this->_font(U"LEVEL : {}"_fmt(this->_level)).draw(score_x, score_y + 50);
	this->_minifont(U"Next Mino ").draw(next_x + 100, next_y - 50);
	this->_font(U"HIGHSCIRE : {}"_fmt(this->_nowhighscore)).draw(score_x, score_y + 100);
}

GameSystem* GameSystem::GetInstance()
{
	if (gs1 != nullptr) {
		return gs1;
	}
	else {
		throw Error(U"�Q�[���V�X�e��������܂���");
	}
}

void GameSystem::Create()
{
	if (gs1 == nullptr) {
		gs1 = new GameSystem;
	}
}

void GameSystem::Destroy()
{
	if (gs1 != nullptr) {
		delete gs1;
		gs1 = nullptr;
	}
}