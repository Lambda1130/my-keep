#include "SceneMain.h"
#include"DxLib.h"

SceneMain::SceneMain():
	m_player()
{

}

SceneMain::~SceneMain()
{

}

void SceneMain::Init()
{
	m_player.Init();
	m_player.SetFill(true);
	m_player.SetMouseTrase(true);
	for (int i = 0; i < kRectNum; i++)
	{
		m_rect[i].SetRandom();
		m_rect[i].Init();
	}
}

void SceneMain::Update()
{
	m_player.Update();
	for (int i = 0; i < kRectNum; i++)
	{
		m_rect[i].Update();
		//�ړ���̏������ē����蔻����Ƃ�
	 //  if (IsCollision(player, rect[i]))
		if (m_player.IsCollision(m_rect[i]))
		{
			//�������Ă���ꍇ�̏���
			m_rect[i].SetColor(GetColor(255, 0, 0));
		}
		else
		{
			m_rect[i].SetColor(GetColor(255, 255, 255));
		}
	}
}

void SceneMain::Draw()
{
	m_player.Draw();
	for (int i = 0; i < kRectNum; i++)
	{
		m_rect[i].Draw();
	}
}
