#include"Game.h"

Game::Game(const InitData& init_) :
	IScene(init_),
	_mino(make_shared<Mino>(5, 6, 0, Mino_Type::I)),
	_field(Field())
{
	
};

//�^�C�g�����X�V
void Game::update(){
	this->_mino->Update();
}

//�^�C�g�����`��
void Game::draw()const {
	this->_field.Draw();
	this->_mino->Draw();
}
Game::~Game() {
	
}