#include "SceneMapEdit.h"
#include"DxLib.h"
#include <cassert>

#include"Pad.h"

//�t�@�C���̏o�͂Ɏg�p����
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

namespace
{
	constexpr int kCursorRepeatFrame = 4;
}

SceneMapEdit::SceneMapEdit():
	m_cursorX(0),
	m_cursorY(0),
	m_rightRepeatFrame(0),
	m_leftRepeatFrame(0),
	m_upRepeatFrame(0),
	m_downRepeatFrame(0)
{
	//�O���t�B�b�N�̃��[�h
	m_bgHandle = LoadGraph("data/image/bg.png");
	assert(m_bgHandle != -1);

	//�}�b�v�`�b�v�̐��𐔂���
	int graphW = 0;
	int graphH = 0;
	GetGraphSize(m_bgHandle, &graphW, &graphH);

	m_graphChipNumX = graphW / kChipWidth;
	m_graphChipNumY = graphH / kChipHeight;

	//�`�b�v�̔z�u���
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
	//�O���t�B�b�N�̉��

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
//	if ((pad & PAD_INPUT_UP) != 0)

	if (Pad::IsPress(PAD_INPUT_UP))
	{
		m_upRepeatFrame++;
		if (m_upRepeatFrame >= kCursorRepeatFrame)
		{
			m_upRepeatFrame = 0;

			//�J�[�\���̈ړ�����
			CursorUp(Pad::IsTrigger(PAD_INPUT_UP));
		}
	}

	if (Pad::IsPress(PAD_INPUT_DOWN))
	{
		m_downRepeatFrame++;
		if (m_downRepeatFrame >= kCursorRepeatFrame)
		{
			m_downRepeatFrame = 0;
			CursorDown(Pad::IsTrigger(PAD_INPUT_DOWN));
		}

	}

	if (Pad::IsPress(PAD_INPUT_LEFT))
	{
		m_leftRepeatFrame++;
		if (m_leftRepeatFrame >= kCursorRepeatFrame)
		{
			m_leftRepeatFrame = 0;
			CursorLeft(Pad::IsTrigger(PAD_INPUT_LEFT));

		}
	}

	//�E�����ւ̃J�[�\���ړ�
	if (Pad::IsPress(PAD_INPUT_RIGHT))
	{
		m_rightRepeatFrame++;
		if (m_rightRepeatFrame >= kCursorRepeatFrame)
		{
			m_rightRepeatFrame = 0;

			//�J�[�\���ړ�����
			CursorRight(Pad::IsTrigger(PAD_INPUT_RIGHT));
		}
	}
	if (Pad::IsTrigger(PAD_INPUT_1))
	{
		assert(m_cursorX >= 0 && m_cursorX < kChipNumX);
		assert(m_cursorY >= 0 && m_cursorX < kChipNumX);

		//�I�����Ă���}�b�v�`�b�v�ԍ���+1
		m_chipData[m_cursorY][m_cursorX]++;

		//�O���t�B�b�N���ɑ��݂���}�b�v�`�b�v�̐�
		int chipNum = GetGraphChipNum();

	
		//���[�v����
		if (m_chipData[m_cursorY][m_cursorX] > chipNum-1)
		{
			m_chipData[m_cursorY][m_cursorX] = 0;
		}

	}
	if (Pad::IsTrigger(PAD_INPUT_2))
	{
		assert(m_cursorX >= 0 && m_cursorY < kChipNumY);
		assert(m_cursorY >= 0 && m_cursorY < kChipNumY);

		//�I�����Ă���}�b�v�`�b�v�ԍ���-1
		m_chipData[m_cursorY][m_cursorX]--;

		//�O���t�B�b�N���ɑ��݂���}�b�v�`�b�v�̐�
		int chipNum = GetGraphChipNum();

		//���[�v����
		if (m_chipData[m_cursorY][m_cursorX] < 0)
		{
			m_chipData[m_cursorY][m_cursorX] = chipNum - 1;
		}
	}

	//�t�@�C���o�̓e�X�g
	if (Pad::IsTrigger(PAD_INPUT_3))  
	{
		fstream file;

		file.open("test.txt",ios::out);  //�t�@�C�����J�� 
	
		//�t�@�C�����J���̂Ɏ��s�����ꍇ�̏���
		if (!file.is_open())
		{
			//�t�@�C�����J���Ȃ������ꍇ�̏���
			// return EXIT_FAILURE; //���ȏ��͊J���Ȃ������炻�̎��_�Ńv���O�����I��
			printfDx("�t�@�C�����J���̂Ɏ��s���܂����B\n");
		}
		else
		{
			//�t�@�C�����J�����ꍇ�̏���
			file << "�t�@�C���ɏ������񂶂Ⴆ�B" << endl;

			//���l�̏������݃e�X�g
			int num = 100;
			file << num << endl;
			file.close();

			printfDx("�t�@�C���ɏ������݂��s���܂����B\n");
		}
	}

	//�t�@�C���ǂݍ��݃e�X�g
	if (Pad::IsTrigger(PAD_INPUT_4))
	{

	}
}

void SceneMapEdit::Draw()
{
	for (int y = 0; y < kChipNumY; y++)
	{
		for (int x = 0; x < kChipNumX; x++)
		{
			//�}�b�v��񂩂�u���`�b�v���Ƃ��Ă���
			int chipNo = m_chipData[y][x];

			//�}�b�v�`�b�v�̃O���t�B�b�N�؂�o�����W
			int srcX = kChipWidth * (chipNo % m_graphChipNumX);
			int srcY = kChipHeight * (chipNo / m_graphChipNumX);


			DrawRectGraph(x * kChipWidth, y * kChipHeight, srcX, srcY, kChipWidth, kChipHeight, m_bgHandle, true);
		}

	}

	//�O���b�g�̕\��

	//�c��
	for (int x = 0; x < kChipNumX; x++)
	{
		DrawLine(x * kChipWidth, 0, x * kChipWidth, Game::kScreenHeight,GetColor(255,255,255));
	}
	//����
	for (int y = 0; y < kChipNumY; y++)
	{
		DrawLine(0,y * kChipHeight, Game::kScreenWidth,y* kChipHeight, GetColor(255, 255, 255));
	}


	//���ݑI�����Ă���`�b�v�ɃJ�[�\����\��
	int cursorPosX = m_cursorX * kChipWidth;
	int cursorPosY = m_cursorY * kChipHeight;
	DrawBox(cursorPosX, cursorPosY,    //������W 
		cursorPosX + kChipWidth, cursorPosY + kChipHeight,  //�E�����W 
		GetColor(255, 0, 0), false);
	DrawBox(cursorPosX+1, cursorPosY+1,    //������W 
		cursorPosX + kChipWidth-1, cursorPosY + kChipHeight-1,  //�E�����W 
		GetColor(255, 0, 0), false);
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
	if (kChipNumY - 1 < m_cursorY)
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

void SceneMapEdit::CursorRight(bool isLoop)
{
	m_cursorX++;
	if (kChipNumX - 1 < m_cursorX)
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

int SceneMapEdit::GetGraphChipNum()
{
	return m_graphChipNumX * m_graphChipNumY;;
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

void SceneMapEdit::OutputBinary()
{
	std::fstream file;



	// �o�C�i�����[�h�ŊJ��
	// �g���q�͂Ȃ�ł��悢�@�o�C�i���f�[�^��\��bin, �f�[�^��\��dat�������W���[
	file.open("map.bin", std::ios::out | std::ios::binary);



	if (!file.is_open())
	{
		printfDx("�t�@�C�����J���̂Ɏ��s���܂���\n");
	}
	else
	{
		// �}�b�v�`�b�v�̔z�u�f�[�^���o�C�i���ŏo��

		// fstream��write�֐����g�p���ďo�͂���
		// ��������̂ǂ��ɒu���Ă��邩(�A�h���X)��
		// �������牽�o�C�g�o�͂��邩�A���w�肷��
		file.write((const char*)&m_chipData, sizeof(m_chipData));



		file.close();



		printfDx("�o�C�i���f�[�^�Ƃ��ă}�b�v�f�[�^���o�͂��܂���\n");
	}
}



void SceneMapEdit::InputBinary()
{
	std::fstream file;



	// �o�C�i�����[�h�ŊJ��
	file.open("map.bin", std::ios::in | std::ios::binary);



	if (!file.is_open())
	{
		printfDx("�t�@�C�����J���̂Ɏ��s���܂���\n");
	}
	else
	{
		// �ǂݍ��񂾃o�C�i���̓��e����������̃}�b�v�`�b�v���ɏ㏑������
		file.read((char*)&m_chipData, sizeof(m_chipData));



		file.close();



		printfDx("�o�C�i���f�[�^�Ƃ��ă}�b�v�f�[�^����͂��܂���\n");
	}
}
