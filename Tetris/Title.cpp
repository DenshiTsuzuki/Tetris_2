#include "Title.h"
Title::Title(const InitData& init_) : IScene(init_) 
{

};

//�^�C�g�����X�V
void Title::update(){

	if (KeyR.down()) {
		changeScene(State::Game);
	}
}

//�^�C�g�����`��
void Title::draw()const {

	
}