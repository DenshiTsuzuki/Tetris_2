#include"Game.h"

Game::Game(const InitData& init_) :
	IScene(init_),
	_mino(Mino(5,6,0,Mino_Type::J)),
	_field(Field())
	
{
	
};

//�^�C�g�����X�V
void Game::update(){
	
}

//�^�C�g�����`��
void Game::draw()const {
	this->_field.Draw();
	this->_mino.Draw();
}
Game::~Game() {
	
}