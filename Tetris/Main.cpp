#pragma once
#include"Title.h"
#include"Game.h"
#include"End.h"
void Main()
{
	const int32 scene_x = 1200;
	const int32 scene_y = 960;
	Scene::Resize(scene_x, scene_y);

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