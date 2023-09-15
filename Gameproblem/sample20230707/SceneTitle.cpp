#include "SceneTitle.h"
#include"DxLib.h"
#include"Game.h"

SceneTitle::SceneTitle():
	m_isSceneEnd(false),
	m_decideSe(-1),
	m_bgmHandle(-1),
	m_fadeAlpha(255)
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	//BGM
	m_bgmHandle = LoadSoundMem("data/image/title.wav");

	//効果音の読み込み
	m_decideSe=LoadSoundMem("data/image/title.mp3");

	//bgmの再生
	PlaySoundMem(m_bgmHandle, DX_PLAYTYPE_LOOP);
	//フェードインさせるため音量0から始める
	ChangeVolumeSoundMem(0,m_bgmHandle);

	m_isSceneEnd = false;
}

void SceneTitle::Update()
{
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (pad & PAD_INPUT_1) //パットの１ボタン or　キーボードのzキー
	{
		if (!m_isSceneEnd)
		{
			//効果音鳴らす
			//PlaySoundFile("data/image/title.mp3",DX_PLAYTYPE_BACK);
			PlaySoundMem(m_decideSe, DX_PLAYTYPE_BACK);
		}

		//タイトル画面を終了してSceneMainに移動する処理を書きたい
		m_isSceneEnd = true;
	}
	if (m_isSceneEnd)
	{
		m_fadeAlpha += 8;
		if (m_fadeAlpha > 255)
		{
			m_fadeAlpha = 255;
		}
	}
	else
	{
		m_fadeAlpha -= 8;
		if (m_fadeAlpha < 0)
		{
			m_fadeAlpha = 0;
		}
	}
	//画面のフェード値を利用してサウンドの音量を決定する
	int volume = 255 - m_fadeAlpha;
	ChangeVolumeSoundMem(volume, m_bgmHandle);
}

void SceneTitle::Draw()
{
	DrawString(120, 120, "タイトル画面", GetColor(255, 255, 255));
	DrawString(120, 120+16, "1ボタンを押してください", GetColor(255, 255, 255));

	//フェードの描画
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeAlpha);
	DrawBox(0, 0, Game::kSreenWidth, Game::kSreenHeigt, GetColor(0, 0, 0), true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, m_fadeAlpha);
}

void SceneTitle::End()
{
	StopSoundMem(m_bgmHandle);

	//bgm
	DeleteSoundMem(m_bgmHandle);
	//効果音
	DeleteSoundMem(m_decideSe);
}

bool SceneTitle::IsSceneEnd() const
{
	return m_isSceneEnd && (m_fadeAlpha >= 255);
}
