#pragma once
#include<Siv3D.hpp>
using namespace std;

enum class State {
	Title,
	Game,
	End
};

//�V�[���ׂ��ŋ��L�������
struct GameData {
	int HighScore = 0;
};

using Task_Scene = SceneManager < State, GameData >;

enum class Mino_Type :int{
	I = 2,
	O ,
	T ,
	J ,
	L ,
	S ,
	Z 
};

//�v���C���[�ۑ�
struct Player {
	String _name;
	int _level;
	int _score;
	Player() :
		_name(U"P1"), 
		_level(0),
		_score(0) 
	{

	}
};

//�v���C���[
static Player player;

//�t�B�[���h�z��
#define field_size_x 12
#define field_size_y 21

//��`�T�C�Y
#define mino_s 25

//�t�B�[���h�\�������ʒu
#define field_x 40
#define field_y 60

//4*4
#define mino_wh 4

//�������ԏ����l
#define def_interval 24