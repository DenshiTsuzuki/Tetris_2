#include "End.h"
End::End(const InitData& init_) : 
	IScene(init_) ,
	_bigfont(80, U"example/font/AnnyantRoman/AnnyantRoman.ttf"),
	_font(30, U"example/font/AnnyantRoman/AnnyantRoman.ttf"),
	_targetNum(0),
	_target(Rect(Scene::Center().x - 300 - 150, Scene::Center().y + 200 - 30,300,60)),
	_targetPos{
		Point(Scene::Center().x - 300, Scene::Center().y + 200),
		Point(Scene::Center().x + 200, Scene::Center().y + 200)
	}
{
	//�G���f�B���O�������������Ȃ��̂ł������񂱂��
	AudioAsset(U"TitleBGM").setLoop(true);
	AudioAsset(U"TitleBGM").setVolume(0.3);
	AudioAsset(U"TitleBGM").play();
}
End::~End()
{

	if (AudioAsset(U"TitleBGM").isPlaying()) {
		AudioAsset(U"TitleBGM").pause();
	}
};

//�^�C�g�����X�V
void End::update(){
	//�I�𒆁@�̈ʒu��ς���
	if (KeyRight.down() || KeyLeft.down()) {
		//����炷
		AudioAsset(U"Select").play();

		//�^�[�Q�b�g�ύX
		this->_targetNum = (this->_targetNum + 1) % 2;
		_target.x = _targetPos[_targetNum].x - _target.w / 2;
		_target.y = _targetPos[_targetNum].y - _target.h / 2;
	}

	if (KeyEnter.down()) {
		//�T�E���h
		AudioAsset(U"Input").playOneShot();

		switch (this->_targetNum) {
		case 0://�������Q�[����
			changeScene(State::Game);
			break;
		case 1://�Q�[���I��
			System::Exit();
			break;
		}
	}

}

//�^�C�g�����`��
void End::draw()const {
	Point sc = Scene::Center();

	_bigfont(U"thanks for playing!!").drawAt(sc.x,sc.y - 200);
	_font(U"Take High Score").drawAt(_targetPos[0]);
	_font(U"Exit game").drawAt(_targetPos[1]);
	_target.drawFrame(0, 2, ColorF(1.f, 1.f, 1.f, Periodic::Sine0_1(1s)));
}