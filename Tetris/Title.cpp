#include "Title.h"
Title::Title(const InitData& init_) : 
	IScene(init_),
	_font(50, U"example/font/AnnyantRoman/AnnyantRoman.ttf"),
	_titlefont(100, U"example/font/AnnyantRoman/AnnyantRoman.ttf")
{

};

//�^�C�g�����X�V
void Title::update(){

	if (KeyEnter.down()) {
		changeScene(State::Game);
	}
}

//�^�C�g�����`��
void Title::draw()const {
	_titlefont(U"Tetris  Game!!").drawAt(Scene::Center().x,Scene::Center().y - 200);

	//1�b�Ԋu�ŃT�C���J�[�u��alpha�l��ς���
	_font(U"Press Enter").drawAt(Scene::Center().x, Scene::Center().y + 200).drawFrame(0, 4, ColorF(1.f,1.f,1.f, Periodic::Sine0_1(1s)));
}