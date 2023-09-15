#include"DxLib.h"
#include"Enemy.h"
#include<cassert>  //assert.h

namespace 
{
	//�ړ����x
	constexpr int kMoveSpeed = 180;

	//�O���t�B�b�N�̃T�C�Y
	constexpr int kGraphWidth = 64;
	constexpr int kGraphHeight = 64;
}

Enemy::Enemy():
	m_handle(-1),
	m_graphWidth(0),
	m_graphHeight(0),
	m_posX(0),
	m_posY(0),
	m_moveX(kMoveSpeed),
	m_moveY(kMoveSpeed)
{
	if (GetRand(1))
	{
		m_moveX *= -1;
	}

	if (GetRand(1))
	{
		m_moveY *= -1;
	}
}

Enemy::~Enemy()
{
	DeleteGraph(m_handle);
}

void Enemy::Init()
{

}

void Enemy::Update()
{
	m_posX += m_moveX;
	if (m_posX < 0)
	{
		m_posX = 0;
		m_moveX *= -1;  //�i�s����
	}
	if (m_posX > 640 - kGraphWidth)
	{
		m_posX = 640 - kGraphWidth;
		m_moveX *= -1;  //�i�s����
	}

	m_posY += m_moveY;
	if (m_posY < 0)
	{
		m_posY = 0;
		m_moveY *= -1;  //�i�s����
	}
	if (m_posY > 480 - kGraphWidth)
	{
		m_posY = 480 - kGraphWidth;
		m_moveY *= -1;  //�i�s����
	}

}

void Enemy::Draw()const
{
	int posX = m_posX;
	int posY = m_posY;

	posX += GetRand(5) - 2;
	posY += GetRand(5) - 2;

	if (m_moveX > 0)
	{
	   DrawTurnGraph(posX, posY, m_handle, false);  //���E���]
	}
	else
	{
	   DrawGraph(posX, posY, m_handle, false);
	}

}

void Enemy::SetHandle(int handle)
{
	m_handle = handle;

	//�g�p����O���t�B�b�N�̃T�C�Y���擾����
	GetGraphSize(m_handle,&m_graphWidth, &m_graphHeight);
}

void Enemy::SetStartPos()
{
	//�O���t�B�b�N�̃T�C�Y�����肵�ĂȂ���
	//��ʓ��ɕ\������邩��

	//�O���t�B�b�N�����肷��O�ɌĂ΂�Ă����炻��ɋC�Â��悤�ɂ�����
	//�O���t�B�b�N�����܂�O�ɂ����ɗ�����~�܂�悤�ɂ�����
	//assert(�~�܂�Ȃ�����);
	assert(m_handle !=-1);

	m_posX = GetRand(640 - m_graphWidth);
	m_posY = GetRand(480 - m_graphHeight);
}