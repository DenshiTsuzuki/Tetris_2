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
	//エンディング音いいやつ見つからないのでいったんこれで
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

//タイトル内更新
void End::update(){
	//選択中　の位置を変える
	if (KeyRight.down() || KeyLeft.down()) {
		//音を鳴らす
		AudioAsset(U"Select").play();

		//ターゲット変更
		this->_targetNum = (this->_targetNum + 1) % 2;
		_target.x = _targetPos[_targetNum].x - _target.w / 2;
		_target.y = _targetPos[_targetNum].y - _target.h / 2;
	}

	if (KeyEnter.down()) {
		//サウンド
		AudioAsset(U"Input").playOneShot();

		switch (this->_targetNum) {
		case 0://もう一回ゲームへ
			changeScene(State::Game);
			break;
		case 1://ゲーム終了
			System::Exit();
			break;
		}
	}

}

//タイトル内描画
void End::draw()const {
	Point sc = Scene::Center();

	_bigfont(U"thanks for playing!!").drawAt(sc.x,sc.y - 200);
	_font(U"Take High Score").drawAt(_targetPos[0]);
	_font(U"Exit game").drawAt(_targetPos[1]);
	_target.drawFrame(0, 2, ColorF(1.f, 1.f, 1.f, Periodic::Sine0_1(1s)));
}