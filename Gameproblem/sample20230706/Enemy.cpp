#include"DxLib.h"
#include"Enemy.h"
#include<cassert>  //assert.h

namespace 
{
	//移動速度
	constexpr int kMoveSpeed = 180;

	//グラフィックのサイズ
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
		m_moveX *= -1;  //進行方向
	}
	if (m_posX > 640 - kGraphWidth)
	{
		m_posX = 640 - kGraphWidth;
		m_moveX *= -1;  //進行方向
	}

	m_posY += m_moveY;
	if (m_posY < 0)
	{
		m_posY = 0;
		m_moveY *= -1;  //進行方向
	}
	if (m_posY > 480 - kGraphWidth)
	{
		m_posY = 480 - kGraphWidth;
		m_moveY *= -1;  //進行方向
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
	   DrawTurnGraph(posX, posY, m_handle, false);  //左右反転
	}
	else
	{
	   DrawGraph(posX, posY, m_handle, false);
	}

}

void Enemy::SetHandle(int handle)
{
	m_handle = handle;

	//使用するグラフィックのサイズを取得する
	GetGraphSize(m_handle,&m_graphWidth, &m_graphHeight);
}

void Enemy::SetStartPos()
{
	//グラフィックのサイズが決定してないと
	//画面内に表示されるかも

	//グラフィックを決定する前に呼ばれていたらそれに気づくようにしたい
	//グラフィックが決まる前にここに来たら止まるようにしたい
	//assert(止まらない条件);
	assert(m_handle !=-1);

	m_posX = GetRand(640 - m_graphWidth);
	m_posY = GetRand(480 - m_graphHeight);
}