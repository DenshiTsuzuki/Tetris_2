#include"Game.h"
#include"GameSystem.h"
Game::Game(const InitData& init_) :
	IScene(init_)
{
	GameSystem::Create();
};

//�^�C�g�����X�V
void Game::update(){
	GameSystem::GetInstance()->Update();
}

//�^�C�g�����`��
void Game::draw()const {
	GameSystem::GetInstance()->Draw();
}
Game::~Game() {
	GameSystem::Destroy();
}