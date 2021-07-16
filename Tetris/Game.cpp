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

//�^�C�g�����X�V
void Game::update(){
	GameSystem* gs = GameSystem::GetInstance();

	if (gs->_fadecnt > 120) {
		//�n�C�X�R�A�X�V�p���C�^�[
		TextWriter writer(U"gamedata/score.txt",OpenMode::Append);
		if (gs->_nowhighscore < gs->_score) {//�X�V�I
			writer.write(gs->_score);
		}
		changeScene(State::End);
	}

	gs->Update();
}

//�^�C�g�����`��
void Game::draw()const {
	GameSystem::GetInstance()->Draw();
}
Game::~Game() {
	GameSystem::Destroy();
}