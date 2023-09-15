#include "SceneTitle.h"
#include"DxLib.h"

namespace
{
	//フェードの速度
	constexpr int kFadeSpeed = 4;

	//フェードイン後の待ち時間
	constexpr int kWaitFrame = 60;
}

SceneTitle::SceneTitle():
	m_bgNo(0),
	m_fadeCount(0),
	m_fadeSpeed(0),
	m_waitFrame(0)
{
	for (int i = 0; i < KBgNum; i++)
	{
		m_bgHandle[i] = -1;
	}
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
	m_fadeCount = 255;
	m_fadeSpeed = -kFadeSpeed;
	m_waitFrame = 0;

	//グラフィックのロード
	m_bgHandle[0] = LoadGraph("data/kenkenken.jpg");
	m_bgHandle[1] = LoadGraph("data/kenken.jpg");
	m_bgHandle[2] = LoadGraph("data/ken.jpg");
	m_bgHandle[3] = LoadGraph("data/mizuki.gif");
	//最初に表示する画像を指定する
	m_bgNo = 0;
}

void SceneTitle::Update()
{
	/*
	m_fadeCount += m_fadeSpeed;
	if (m_fadeCount < 0)
	{
		//完全にフェードインした
		m_fadeCount = 0;
		//次のフレームからはフェードアウト
		m_fadeSpeed = 1;
	}
	if (m_fadeCount > 255)
	{
		//完成度にフェードアウト
		m_fadeCount = 255;
	}
	*/
	
	if (m_fadeSpeed == 0)
	{
		//待ち時間
		m_waitFrame++;
		if (m_waitFrame >= kWaitFrame)
		{
			//フェードアウトに遷移
			m_fadeSpeed = kFadeSpeed;
		}
	}
	else if (m_fadeSpeed < 0)
	{
		//フェードイン中
		m_fadeCount += m_fadeSpeed;
		if (m_fadeCount <= 0)
		{
			m_fadeCount = 0;
			//待ち時間遷移
			m_fadeSpeed = 0;
			m_waitFrame = 0;  //待ち時間初期化
		}
	}
	else
	{
		//フェードアウト中
		m_fadeCount += m_fadeSpeed;
		if (m_fadeCount >= 255)
		{
			//画像を切り替えてフェードインに遷移する
			m_fadeSpeed = -kFadeSpeed;

			//表示する画像を変更
			m_bgNo++;
			if (m_bgNo >=KBgNum)
			{
				m_bgNo = 0;
			}
		}
	}

}

void SceneTitle::Draw()
{
	DrawGraph(0, 0, m_bgHandle[m_bgNo], false);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeCount);
	DrawBox(0, 0, 640, 480, GetColor(0, 0, 0),true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void SceneTitle::End()
{
	for (int i = 0; i < KBgNum; i++)
	{
	    DeleteGraph(m_bgHandle[0]);
	}

}
