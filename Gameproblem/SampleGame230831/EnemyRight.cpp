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
	// ‘¶İ‚µ‚È‚¢“G‚Íˆ—‚µ‚È‚¢
	if (!m_isExist) return;

	m_posX -= kSpeed;

	// ‰æ–ÊŠO‚Éo‚½‚ç‘¶İ‚ğÁ‚·
	if (m_posX <= 0.0f - m_graphWidht)
	{
		m_isExist = false;
	}
}

void EnemyRight::Draw() const
{
	// ‘¶İ‚µ‚È‚¢“G‚Í•`‰æ‚µ‚È‚¢
	if (!m_isExist) return;

	DrawGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, false);
}

void EnemyRight::Start()
{
	m_isExist = true;

	m_posX = static_cast<float>(Game::kScreenWidth);
	m_posY = static_cast<float>(GetRand(Game::kScreenHeight - m_graphHeight));
}

