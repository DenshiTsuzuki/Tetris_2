#include "End.h"
End::End(const InitData& init_) : IScene(init_) 
{

};

//�^�C�g�����X�V
void End::update(){



	if (KeyR.down()) {
		changeScene(State::Title);
	}
}

//�^�C�g�����`��
void End::draw()const {

	
}