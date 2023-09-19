#include "EnemyRight.h"
#include "DxLib.h"
#include "Game.h"



#include <cassert>



namespace
{
    constexpr float kSpeed = 4.0f;
}



EnemyRight::EnemyRight() :
    m_handle(-1),
    m_isExist(false),
    m_posX(static_cast<float>(GetRand(Game::kScreenWidth))),
    m_posY(static_cast<float>(GetRand(Game::kScreenHeight))),
    m_graphWidth(0),
    m_graphHeight(0)
{



}



EnemyRight::~EnemyRight()
{



}



void EnemyRight::Init()
{



}



void EnemyRight::Update()
{
    //ë∂ç›ÇµÇ»Ç¢ìGÇÃèàóùÇÕÇµÇ»Ç¢
    if (!m_isExist)
        return;



    m_posX -= kSpeed;



    //âÊñ äOÇ…èoÇΩÇÁë∂ç›Çè¡Ç∑



    if (m_posX < 0.0f - m_graphWidth)
    {
        m_isExist = false;
    }
}



void EnemyRight::Draw()
{
    //ë∂ç›ÇµÇ»Ç¢ìGÇÃèàóùÇÕÇµÇ»Ç¢
    if (!m_isExist)
        return;



    DrawTurnGraph(static_cast<int>(m_posX), static_cast<int>(m_posY), m_handle, false);
}

void EnemyRight::start()
{
    m_isExist = true;

    GetGraphSize(m_handle, &m_graphWidth, &m_graphHeight);

    m_posX = static_cast<float>(Game::kScreenWidth);
    m_posY = static_cast<float>(GetRand(Game::kScreenHeight - m_graphHeight));
}
