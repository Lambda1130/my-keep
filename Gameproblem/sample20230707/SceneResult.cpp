#include "SceneResult.h"
#include"DxLib.h"
#include"Game.h"

SceneResult::SceneResult():
	m_gameoverHandle(-1),
	m_bgmHandle(-1),
	m_isSceneEnd(false)
{
}

SceneResult::~SceneResult()
{
}

void SceneResult::Init()
{
	m_gameoverHandle=LoadGraph("data/sound/gameover.png ");
	m_bgmHandle== LoadGraph("data/image/result.wav ");

	PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);
}

void SceneResult::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_2) //パットの１ボタン or　キーボードのzキー
	{
		//タイトル画面を終了してSceneMainに移動する処理を書きたい
		m_isSceneEnd = true;
	}
}

void SceneResult::Draw()
{
	int width=0;
	int height=0;
	GetGraphSize(m_gameoverHandle, &width, &height);

	DrawGraph(Game::kSreenWidth/2- width/2,
		Game::kSreenHeigt/2-height/2 ,
		m_gameoverHandle,false);

	DrawString(550, 600, "2ボタンを押してください", GetColor(255, 255, 255));
}

void SceneResult::End()
{
	DeleteGraph(m_gameoverHandle);
	DeleteGraph(m_bgmHandle);

	StopSoundMem(m_bgmHandle);

}
