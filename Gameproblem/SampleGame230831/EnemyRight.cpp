#include <DxLib.h>

#include "EnemyRight.h"

#include "Game.h"

namespace
{
	constexpr float kSpeed = 4.0f;
}

EnemyRight::EnemyRight() :
	m_handle(-1),
	m_graphWidht(0),
	m_graphHeight(0),
	m_isExist(false),
	m_posX( static_cast<float>(Game::kScreenWidth) ),
	m_posY( static_cast<float>(Game::kScreenHeight) )
{
}

EnemyRight::~EnemyRight()
{
}

void EnemyRight::Init()
{
	GetGraphSize(m_handle, &m_graphWidht, &m_graphHeight);
}

void EnemyRight::Update()
{
	// 存在しない敵は処理しない
	if (!m_isExist) return;

	m_posX -= kSpeed;

	// 画面外に出たら存在を消す
	if (m_posX <= 0.0f - m_graphWidht)
	{
		m_isExist = false;
	}
}

void EnemyRight::Draw() const
{
	// 存在しない敵は描画しない
	if (!m_isExist) return;

	DrawGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, false);
}

void EnemyRight::Start()
{
	m_isExist = true;

	m_posX = static_cast<float>(Game::kScreenWidth);
	m_posY = static_cast<float>(GetRand(Game::kScreenHeight - m_graphHeight));
}

