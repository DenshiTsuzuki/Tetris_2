#pragma once
#include"Title.h"
#include"Game.h"
#include"End.h"

void Main()
{
	const int32 scene_x = 1200;
	const int32 scene_y = 900;
	Scene::Resize(scene_x, scene_y);
	Window::Resize(scene_x, scene_y);
	//背景変更
	Scene::SetBackground(Palette::Darkslateblue);
	//テクスチャの登録
	TextureAsset::Register(U"Block", U"image/Block.png", TextureDesc::Mipped);

	//サウンドの登録
	AudioAsset::Register(U"Input", U"sound/button.mp3");	//入力音
	AudioAsset::Register(U"Select", U"sound/select.mp3");	//入力変更音
	AudioAsset::Register(U"Rot", U"sound/rot.mp3");			//回転音
	AudioAsset::Register(U"MinoInput", U"sound/MinoInput.mp3");
	AudioAsset::Register(U"TitleBGM",U"sound/TitleBGM.mp3");
	AudioAsset::Register(U"GameBGM", U"sound/GameBGM.mp3");

	//シーン遷移管理
	Task_Scene task_scene;
	task_scene
		.add<Title>(State::Title)
		.add<Game>(State::Game)
		.add<End>(State::End);

	while (System::Update()) {
		if (!task_scene.update())
		{
			break;
		}
	}
}