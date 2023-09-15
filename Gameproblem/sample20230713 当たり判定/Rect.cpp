#include "Rect.h"
#include"DxLib.h"

namespace 
{
	//ランダムに生成する矩形のサイズを制限
	constexpr int kWidthMin = 32;  //最小幅
	constexpr int kWidthMax = 128;  //最大幅

	constexpr int kHeightMin = 24;  //最大幅
	constexpr int kHeightMax = 96;  //最大幅

}

Rect::Rect():
	m_posX(320),
	m_posY(240),
	m_width(32),
	m_height(32),
	m_color(GetColor(255,255,0)),
	m_isFill(false),
	m_isMoreTrase(false)
{

}

Rect::~Rect()
{

}

void Rect::Init()
{

}

void Rect::Update()
{
	//マウス追従フラグ
	if (m_isMoreTrase)
	{
		GetMousePoint(&m_posX, &m_posY);
	}
}

void Rect::Draw()
{
	DrawBox(GetLeft(), GetTop(), GetRight(), GetBottom(), m_color, m_isFill);
}

void Rect::SetRandom()
{
	m_posX = GetRand(640);
	m_posY = GetRand(480);
	m_width = GetRand(kWidthMax - kWidthMin) + kWidthMin;
	m_height = GetRand(kHeightMax - kHeightMin) + kHeightMin;
}

bool Rect::IsCollision(const Rect& target) const
{
	//自身の完全に左にいる場合は当たっていない
	if (GetLeft() > target.GetRight())
	{
		return false;
	}
	//自身の完全に下にいる場合当たっていない
	if (GetBottom() < target.GetTop())
	{
		return false;
	}
	//自身の完全に右にいる場合当たっていない
	if (GetRight() < target.GetLeft())
	{
		return false;
	}
	//自身の完全に上にいる場合当たっていない
	if (GetTop() > target.GetBottom())
	{
		return false;
	}
	//完全に当たっていないパターンを取り除いて
	//残ったやつは当たっている
	return true;
}

int Rect::GetLeft() const
{
	return m_posX - m_width / 2;
}

int Rect::GetTop() const
{
	return m_posY - m_height / 2;
}

int Rect::GetRight() const
{
	return m_posX + m_width / 2;
}

int Rect::GetBottom() const
{
	return m_posY + m_height / 2;
}
