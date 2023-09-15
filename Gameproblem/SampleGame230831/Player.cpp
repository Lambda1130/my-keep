#include <DxLib.h>

#include "Player.h"

#include "Game.h"

namespace
{
	// �ړ����x
	constexpr float kSpeed = 3.0f;

	//�L�����N�^�[�̃T�C�Y
	constexpr int kWidth = 32;
	constexpr int kHeight = 32;

	//�L�����N�^�[�̃A�j���[�V����
	constexpr int kUseFram[] = { 0,1,2,1 };
	//�A�j���[�V������1�R�}�̃t���[����
	constexpr int kAnimFrameNum = 8;
	//�A�j���[�V����1�T�C�N���̃t���[����
	constexpr int kAnimFrameCyclre = _countof(kUseFram) * kAnimFrameNum;
}

Player::Player() :
	m_handle(-1),
	m_graphWidht(0),
	m_graphHeight(0),
	m_posX(Game::kScreenWidth / 2),
	m_posY(Game::kScreenHeight / 2),
	m_dir(kDirDown),
	m_walkAnimFrame(0)
{
}

Player::~Player()
{
}

void Player::Init()
{
	GetGraphSize(m_handle, &m_graphWidht, &m_graphHeight);
}

void Player::Update()
{
	


	// �p�b�h�̏\���L�[���g�p���ăv���C���[���ړ�������
	int pad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	bool isMove = false; //�ړ������ǂ���

	if (pad & PAD_INPUT_LEFT)
	{
		m_posX -= kSpeed;
		m_dir = kDirLeft;
		isMove = true;


		if (m_posX < 0)	m_posX = 0;
	}
	if (pad & PAD_INPUT_RIGHT)
	{
		m_posX += kSpeed;
		m_dir = kDirRight;
		isMove = true;

		if (Game::kScreenWidth - m_graphWidht < m_posX)	m_posX = Game::kScreenWidth - m_graphWidht;
	}
	if (pad & PAD_INPUT_UP)
	{
		m_posY -= kSpeed;
		m_dir = kDirUp;
		isMove = true;

		if (m_posY < 0)	m_posY = 0;
	}
	if (pad & PAD_INPUT_DOWN)
	{
		m_posY += kSpeed;
		m_dir = kDirDown;
		isMove = true;

		if (Game::kScreenHeight - m_graphHeight < m_posY)	m_posY = Game::kScreenHeight - m_graphHeight;
	}

	if (isMove)
	{
	//�����A�j���[�V����
		m_walkAnimFrame++;
		if (m_walkAnimFrame > kAnimFrameCyclre)   m_walkAnimFrame = 0;
	}
}

void Player::Draw() const
{
	int animFrame = m_walkAnimFrame / kAnimFrameNum;

	int srcX = kUseFram[animFrame] * kWidth;
	int srcY = kWidth * m_dir;
/*
	switch (m_dir)
	{
	case kDirDown:
		srcY = 32 * 0;
		break;
	case kDirLeft:
		srcY = 32 * 1;
		break;
	case kDirRight:
		srcY = 32 * 2;
		break;
	case kDirUp:
		srcY = 32 * 3;
		break;

	}
	*/
		DrawRectGraph(static_cast<int>(m_posX), static_cast<int>(m_posY),
			srcX, srcY, kWidth, kHeight, m_handle, true);
}

