#include "End.h"
End::End(const InitData& init_) : IScene(init_) 
{

};

//タイトル内更新
void End::update(){



	if (KeyR.down()) {
		changeScene(State::Title);
	}
}

//タイトル内描画
void End::draw()const {

	
}