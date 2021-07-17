#include"Game.h"
#include"GameSystem.h"
Game::Game(const InitData& init_) :
	IScene(init_),
	_mino(make_unique<Mino>(4, 0, Mino_Type::O)),
	_nextmino(make_unique<Mino>(4, 0, Mino_Type::T)),
	_holdmino(make_unique<Mino>(4, 0, Mino_Type::non)),
	_field(make_unique<Field>()),
	_isGameOver(false),
	_isHold(false),
	_fadecnt(9),
	_score(0),
	_level(1),
	_nowhighscore(0),
	_font(40, U"example/font/AnnyantRoman/AnnyantRoman.ttf"),
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

	//BGM����
	AudioAsset(U"GameBGM").setLoop(true);
	AudioAsset(U"GameBGM").setVolume(0.3);
	AudioAsset(U"GameBGM").play();

}

Game::~Game() {
	//���~�߂�
	if (AudioAsset(U"GameBGM").isPlaying()) {
		AudioAsset(U"GameBGM").pause();
	}
}

void Game::ScorePuls(int i_)
{
	//�X�R�A���Z�p
	int scoredef[5] = { 0,100,300,600,1000 };

	this->_score += scoredef[i_];
}

void Game::Fade(int f_)
{
	if (this->_fadecnt > f_) {
		//�n�C�X�R�A�X�V�p���C�^�[
		TextWriter writer(U"gamedata/score.txt", OpenMode::Append);
		if (this->_nowhighscore < this->_score) {//�X�V�I
			writer.write(this->_score);
		}
		changeScene(State::End);
	}
}
void Game::ChangeMino()
{
	//���삷��~�m��ύX
	if (this->_mino == nullptr && this->_nextmino != nullptr) {
		//�ύX��fallinterval��ύX����
		this->_nextmino->_interval -= this->_level - 1;
		this->_mino.swap(_nextmino);

		//�~�m�������ڐG���肪����΃Q�[���I�[�o�[
		this->_isGameOver = this->_field->CheckHit(&_mino->_pos, &bdp[(int)_mino->_type][_mino->_rot]);

		//�z�[���h�\�ɂ���
		this->_isHold = false;
	}
}
void Game::MinoHold()
{
	//�z�[���h�͈�����܂�
	if (this->_isHold == true)return;

	//�z�[���h�ƕύX
	if (this->_mino != nullptr) {
		this->_mino.swap(this->_holdmino);

		//�폜
		if (this->_mino->_type == Mino_Type::non) {
			this->_mino.release();
		}
	}
	//�|�W�V����������
	this->_holdmino->_pos = Point(4, 0);
	this->_isHold = true;
};

//�Q�[�����X�V
void Game::update(){
	//�t�F�[�h�A�E�g���s
	this->Fade(120);

	//�Q�[���I�[�o�[�Ȃ炱��ȍ~�̏������s��Ȃ�
	if (_isGameOver == true) {
		++this->_fadecnt;
		return;
	}

	//�Ֆʂő���ł���~�m�̃A�b�v�f�[�g���s
	if (this->_mino != nullptr) {
		this->_mino->Update(this,*_field);

		//���s�I����non�Ȃ烊���[�X
		if (this->_mino->_type == Mino_Type::non) {
			this->_mino.release();
		}
	}

	//�z�[���h�~�m�Ƃ̕ύX
	if (KeyC.down()) {
		this->MinoHold();
	}

	//���삷��~�m��ύX
	this->ChangeMino();

	//�l�N�X�g�~�m���� �Ƃ肠���������_��
	if (this->_nextmino == nullptr) {
		int i = Random(1, 7);
		_nextmino = make_unique<Mino>(4, 0, Mino_Type(i));

	}

	//���x���̕ύX
	this->_level = 1 + this->_score / 1000;

}

//�^�C�g�����`��
void Game::draw()const {
	//�t�B�[���`��
	this->_field->Draw();

	//�Ֆʏ�̃~�m
	if (this->_mino != nullptr) {
		this->_mino->Draw(field_x, field_y);
	}

	//�l�N�X�g�~�m
	if (this->_nextmino != nullptr) {
		this->_nextmino->DrawWithGrid(next_x, next_y);
	}

	//�z�[���h�~�m
	if (this->_holdmino != nullptr) {
		this->_holdmino->DrawWithGrid(next_x + 200, next_y);
	}

	this->_font(U"SCORE : {}"_fmt(this->_score)).draw(score_x, score_y);
	this->_font(U"LEVEL : {}"_fmt(this->_level)).draw(score_x, score_y + 50);
	this->_minifont(U"Next Mino ").draw(next_x + 100, next_y - 50);
	this->_minifont(U"Hold").draw(next_x + 350, next_y - 50);
	this->_font(U"HIGHSCIRE : {}"_fmt(this->_nowhighscore)).draw(score_x, score_y + 100);
}
