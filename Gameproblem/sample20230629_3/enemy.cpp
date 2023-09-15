#include"enemy.h"
#include"DxLib.h"

//定数を定義
namespace
{
	//初期位置
	constexpr int kDefaultPosX = 320;
	constexpr int kDefaultPosY = 240;
	//半径
	constexpr int kRadius = 48;
	//色
	const unsigned int kWhiteColor = GetColor(200, 200, 200);
	const unsigned int kRedColor = GetColor(255, 255, 0);
}

Enemy::Enemy():
	m_posX(kDefaultPosX),
	m_posY(kDefaultPosY)
{


}

Enemy::~Enemy()
{

}

void Enemy::init()
{

}

void Enemy::update()
{

}


void Enemy::kDefaultColor()
{
	DrawCircle(m_posX, m_posY, kRadius,kWhiteColor, true);
}

void Enemy::redColor()
{
	DrawCircle(m_posX, m_posY, kRadius, kRedColor, true);
}

void Enemy::setPosX(int x)
{
	//不正な値設定された場合、不正じゃないようにしたりできる
	m_posX = x;

	//
	if (m_posX < 320)
	{
		m_posX = 0;
	}
	if (m_posX > 640)
	{
		m_posX = 640;
	}
 
}

int Enemy::getRadius()
{
	return kRadius;
}