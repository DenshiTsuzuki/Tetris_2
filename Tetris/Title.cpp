#include "Title.h"
Title::Title(const InitData& init_) : IScene(init_) 
{

};

//タイトル内更新
void Title::update(){

	if (KeyR.down()) {
		changeScene(State::Game);
	}
}

//タイトル内描画
void Title::draw()const {

	
}