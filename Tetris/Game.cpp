#include"Game.h"
#include"GameSystem.h"
Game::Game(const InitData& init_) :
	IScene(init_)
{
	GameSystem::Create();
}
void Game::Fade()
{
}
;

//タイトル内更新
void Game::update(){
	GameSystem* gs = GameSystem::GetInstance();

	if (gs->_fadecnt > 120) {
		//ハイスコア更新用ライター
		TextWriter writer(U"gamedata/score.txt",OpenMode::Append);
		if (gs->_nowhighscore < gs->_score) {//更新！
			writer.write(gs->_score);
		}
		changeScene(State::End);
	}

	gs->Update();
}

//タイトル内描画
void Game::draw()const {
	GameSystem::GetInstance()->Draw();
}
Game::~Game() {
	GameSystem::Destroy();
}