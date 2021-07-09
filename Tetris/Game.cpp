#include"Game.h"
#include"GameSystem.h"
Game::Game(const InitData& init_) :
	IScene(init_)
{
	GameSystem::Create();
};

//タイトル内更新
void Game::update(){
	GameSystem::GetInstance()->Update();
}

//タイトル内描画
void Game::draw()const {
	GameSystem::GetInstance()->Draw();
}
Game::~Game() {
	GameSystem::Destroy();
}