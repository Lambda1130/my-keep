#include "enemy.h"
#include "DxLib.h"

Enemy::Enemy() :
	m_handle(LoadGraph("data/obj.png")),
	m_posX(320),
	m_posY(240)
{

}

//デストラクタ
Enemy::~Enemy()
{
	DeleteGraph(m_handle);
}

void Enemy::init()
{

}

void Enemy::draw()
{
	DrawGraph(m_posX, m_posY, m_handle, false);
}

void Enemy::setPos(int x, int y)
{
	//画面外に出ていたら戻す処理
	if (x < 0)  x = 0;
	if (x > 640 - 32) x = 640 - 32;
	if (y < 0) y = 0;
	if (y > 480 - 32) y = 480 - 32;

	m_posX = x;
	m_posY = y;

}