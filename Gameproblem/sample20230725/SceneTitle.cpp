#include "SceneTitle.h"
#include"DxLib.h"

namespace
{
	//�t�F�[�h�̑��x
	constexpr int kFadeSpeed = 4;

	//�t�F�[�h�C����̑҂�����
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

	//�O���t�B�b�N�̃��[�h
	m_bgHandle[0] = LoadGraph("data/kenkenken.jpg");
	m_bgHandle[1] = LoadGraph("data/kenken.jpg");
	m_bgHandle[2] = LoadGraph("data/ken.jpg");
	m_bgHandle[3] = LoadGraph("data/mizuki.gif");
	//�ŏ��ɕ\������摜���w�肷��
	m_bgNo = 0;
}

void SceneTitle::Update()
{
	/*
	m_fadeCount += m_fadeSpeed;
	if (m_fadeCount < 0)
	{
		//���S�Ƀt�F�[�h�C������
		m_fadeCount = 0;
		//���̃t���[������̓t�F�[�h�A�E�g
		m_fadeSpeed = 1;
	}
	if (m_fadeCount > 255)
	{
		//�����x�Ƀt�F�[�h�A�E�g
		m_fadeCount = 255;
	}
	*/
	
	if (m_fadeSpeed == 0)
	{
		//�҂�����
		m_waitFrame++;
		if (m_waitFrame >= kWaitFrame)
		{
			//�t�F�[�h�A�E�g�ɑJ��
			m_fadeSpeed = kFadeSpeed;
		}
	}
	else if (m_fadeSpeed < 0)
	{
		//�t�F�[�h�C����
		m_fadeCount += m_fadeSpeed;
		if (m_fadeCount <= 0)
		{
			m_fadeCount = 0;
			//�҂����ԑJ��
			m_fadeSpeed = 0;
			m_waitFrame = 0;  //�҂����ԏ�����
		}
	}
	else
	{
		//�t�F�[�h�A�E�g��
		m_fadeCount += m_fadeSpeed;
		if (m_fadeCount >= 255)
		{
			//�摜��؂�ւ��ăt�F�[�h�C���ɑJ�ڂ���
			m_fadeSpeed = -kFadeSpeed;

			//�\������摜��ύX
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
