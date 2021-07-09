#pragma once
#include"Title.h"
#include"Game.h"
#include"End.h"
void Main()
{
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