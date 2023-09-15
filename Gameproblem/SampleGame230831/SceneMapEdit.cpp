#include "SceneMapEdit.h"
#include "DxLib.h"
#include <cassert>
#include "Pad.h"

namespace
{
	//�J�[�\���ړ����s�[�g�t���[��
	constexpr int kCursorRepeatFrame = 4;
}

SceneMapEdit::SceneMapEdit() :
	m_cursorX(0),
	m_cursorY(0),
	m_upRepeatFrame(0),
	m_downRepeatFrame(0),
	m_leftRepeatFrame(0),
	m_rightRepeatFrame(0)
{
	//�O���t�B�b�N�̃��[�h
	m_bgHandle = LoadGraph("data/image/bg.png");
	assert(m_bgHandle != -1);

	//�}�b�v�`�b�v�̐��𐔂���
	int graphW = 0;
	int graphH = 0;
	GetGraphSize(m_bgHandle, &graphW, &graphH);

	m_graphChipNumX = graphW / kChipHeight;
	m_graphChipNumY = graphH / kChipHeight;

	//�`�b�v�z�u���̐���
	for (int x = 0; x < kChipNumX; x++)
	{
		for (int y = 0; y < kChipNumY; y++)
		{
			m_chipData[y][x] = 0;
		}
	}
}

SceneMapEdit::~SceneMapEdit()
{
}

void SceneMapEdit::Init()
{
}

void SceneMapEdit::End()
{
}

void SceneMapEdit::Update()
{
	//�J�[�\���̈ړ�
	// �p�b�h�̏\���L�[���g�p���ăv���C���[���ړ�������
	if (Pad::IsPress(PAD_INPUT_UP))
	{
		m_upRepeatFrame++;
		if ((m_upRepeatFrame >= kCursorRepeatFrame) ||
			Pad::IsTrigger(PAD_INPUT_UP))
		{
			m_upRepeatFrame = 0;

			//�J�[�\���̈ړ�����
			CursorUp(Pad::IsTrigger(PAD_INPUT_UP));
		}


	}
	if (Pad ::IsPress(PAD_INPUT_DOWN))
	{
		m_downRepeatFrame++;
		if ((m_downRepeatFrame >= kCursorRepeatFrame) ||
			Pad::IsTrigger(PAD_INPUT_DOWN))
		{
			m_downRepeatFrame = 0;
			//�J�[�\���̈ړ�����
			CursorDown(Pad::IsTrigger(PAD_INPUT_DOWN));
		}
	}
	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		m_leftRepeatFrame++;
		if ((m_leftRepeatFrame >= kCursorRepeatFrame) ||
			Pad::IsTrigger(PAD_INPUT_LEFT))
		{
			m_leftRepeatFrame = 0;

			//�J�[�\���̈ړ�����
			CursorLeft(Pad::IsTrigger(PAD_INPUT_LEFT));
		}
	}
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		m_rightRepeatFrame++;
		if( (m_rightRepeatFrame >= kCursorRepeatFrame) ||
			Pad::IsTrigger(PAD_INPUT_RIGHT))
		{
			m_rightRepeatFrame = 0;

			//�J�[�\���̈ړ�����
			CursorRight(Pad::IsTrigger(PAD_INPUT_RIGHT));
		}
	}
	if (Pad::IsPress(PAD_INPUT_1))
	{



	}
	if (Pad::IsPress(PAD_INPUT_2))
	{



	}
}



void SceneMapEdit::Draw()
{
	//	DrawGraph(0, 0, m_handle, true);

	clsDx();
	printfDx("m_cursorX : %d\n", m_cursorX);
	printfDx("m_cursorY : %d\n", m_cursorY);

	for (int x = 0; x < kChipNumX; x++)
	{
		for (int y = 0; y < kChipNumY; y++)
		{
			//�}�b�v��񂩂�u���`�b�v���Ƃ��Ă���
			int chipNo = m_chipData[y][x];

			//�}�b�v�`�b�v�̃O���t�B�b�N�؂�o�����W
			int srcX = kChipWidth * (chipNo / m_graphChipNumX);
			int srcY = kChipHeight * (chipNo / m_graphChipNumY);

			DrawRectGraph(x * kChipWidth, y * kChipHeight,
				srcX, srcY, kChipWidth, kChipHeight,
				m_bgHandle, true);
		}

		//���ݑI�����Ă���@�`�b�v�ɃJ�[�\����\��
		int cursorPosX = m_cursorX * kChipWidth;
		int cursorPosY = m_cursorY * kChipHeight;
		DrawBox(cursorPosX, cursorPosY, cursorPosX + kChipWidth, cursorPosY + kChipHeight,//������W
			GetColor(255, 0, 0), false); //�E�����W
		//���菬�������i��`�ʂ��Đ��̑����l�p�ɂ���
		DrawBox(cursorPosX + 1, cursorPosY + 1, cursorPosX + kChipWidth - 1, cursorPosY + kChipHeight - 1,
			GetColor(255, 0, 0), false);

	}
}

void SceneMapEdit::CursorUp(bool isLoop)
{
	m_cursorY--;
	if (m_cursorY < 0)
	{
		if (isLoop)
		{
			m_cursorY = kChipNumY - 1;
		}
		else
		{
			m_cursorY = 0;
		}

	}
}

void SceneMapEdit::CursorDown(bool isLoop)
{
	m_cursorY++;
	if (m_cursorY > kChipNumY-1)
	{
		if (isLoop)
		{
			m_cursorY = 0;
		}
		else
		{
		m_cursorY = kChipNumY - 1;
		}
	}
}

void SceneMapEdit::CursorLeft(bool isLoop)
{
	m_cursorX--;
	if (m_cursorX < 0)
	{
		if (isLoop)
		{
			m_cursorX = kChipNumX - 1;
		}
		else
		{
			m_cursorX = 0;
		}

	}
}

void SceneMapEdit::CursorRight(bool isLoop)
{
	m_cursorX++;
	if (m_cursorX > kChipNumX-1)
	{
		if (isLoop)
		{
			m_cursorX = 0;
		}
		else
		{
			m_cursorX = kChipNumX - 1;
		}

	}
}

