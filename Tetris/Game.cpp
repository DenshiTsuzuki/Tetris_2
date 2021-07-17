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
			throw Error(U"スコアファイルがありません");
		}
		String line;
		//一行目を読み込む
		reader.readLine(line);
		this->_nowhighscore = Parse<int>(line);
	}

	//BGM発生
	AudioAsset(U"GameBGM").setLoop(true);
	AudioAsset(U"GameBGM").setVolume(0.3);
	AudioAsset(U"GameBGM").play();

}

Game::~Game() {
	//音止める
	if (AudioAsset(U"GameBGM").isPlaying()) {
		AudioAsset(U"GameBGM").pause();
	}
}

void Game::ScorePuls(int i_)
{
	//スコア加算用
	int scoredef[5] = { 0,100,300,600,1000 };

	this->_score += scoredef[i_];
}

void Game::Fade(int f_)
{
	if (this->_fadecnt > f_) {
		//ハイスコア更新用ライター
		TextWriter writer(U"gamedata/score.txt", OpenMode::Append);
		if (this->_nowhighscore < this->_score) {//更新！
			writer.write(this->_score);
		}
		changeScene(State::End);
	}
}
void Game::ChangeMino()
{
	//操作するミノを変更
	if (this->_mino == nullptr && this->_nextmino != nullptr) {
		//変更時fallintervalを変更する
		this->_nextmino->_interval -= this->_level - 1;
		this->_mino.swap(_nextmino);

		//ミノ生成時接触判定があればゲームオーバー
		this->_isGameOver = this->_field->CheckHit(&_mino->_pos, &bdp[(int)_mino->_type][_mino->_rot]);

		//ホールド可能にする
		this->_isHold = false;
	}
}
void Game::MinoHold()
{
	//ホールドは一日一回まで
	if (this->_isHold == true)return;

	//ホールドと変更
	if (this->_mino != nullptr) {
		this->_mino.swap(this->_holdmino);

		//削除
		if (this->_mino->_type == Mino_Type::non) {
			this->_mino.release();
		}
	}
	//ポジション初期化
	this->_holdmino->_pos = Point(4, 0);
	this->_isHold = true;
};

//ゲーム内更新
void Game::update(){
	//フェードアウト実行
	this->Fade(120);

	//ゲームオーバーならこれ以降の処理を行わない
	if (_isGameOver == true) {
		++this->_fadecnt;
		return;
	}

	//盤面で操作できるミノのアップデート実行
	if (this->_mino != nullptr) {
		this->_mino->Update(this,*_field);

		//実行終了時nonならリリース
		if (this->_mino->_type == Mino_Type::non) {
			this->_mino.release();
		}
	}

	//ホールドミノとの変更
	if (KeyC.down()) {
		this->MinoHold();
	}

	//操作するミノを変更
	this->ChangeMino();

	//ネクストミノ生成 とりあえずランダム
	if (this->_nextmino == nullptr) {
		int i = Random(1, 7);
		_nextmino = make_unique<Mino>(4, 0, Mino_Type(i));

	}

	//レベルの変更
	this->_level = 1 + this->_score / 1000;

}

//タイトル内描画
void Game::draw()const {
	//フィール描画
	this->_field->Draw();

	//盤面上のミノ
	if (this->_mino != nullptr) {
		this->_mino->Draw(field_x, field_y);
	}

	//ネクストミノ
	if (this->_nextmino != nullptr) {
		this->_nextmino->DrawWithGrid(next_x, next_y);
	}

	//ホールドミノ
	if (this->_holdmino != nullptr) {
		this->_holdmino->DrawWithGrid(next_x + 200, next_y);
	}

	this->_font(U"SCORE : {}"_fmt(this->_score)).draw(score_x, score_y);
	this->_font(U"LEVEL : {}"_fmt(this->_level)).draw(score_x, score_y + 50);
	this->_minifont(U"Next Mino ").draw(next_x + 100, next_y - 50);
	this->_minifont(U"Hold").draw(next_x + 350, next_y - 50);
	this->_font(U"HIGHSCIRE : {}"_fmt(this->_nowhighscore)).draw(score_x, score_y + 100);
}
