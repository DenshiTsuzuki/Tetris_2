#include"Game.h"

Game::Game(const InitData& init_) :
	IScene(init_),
	_mino(make_shared<Mino>(5, 6, 0, Mino_Type::I)),
	_field(Field())
{
	
};

//タイトル内更新
void Game::update(){
	this->_mino->Update();
}

//タイトル内描画
void Game::draw()const {
	this->_field.Draw();
	this->_mino->Draw();
}
Game::~Game() {
	
}