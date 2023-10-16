#include "Rect.h"
#include <cassert>
#include"DxLib.h"

Rect::Rect() :
	m_left(0.0f),
	m_top(0.0f),
	m_rigth(0.0f),
	m_bottom(0.0f)
{
}

Rect::~Rect()
{
}

void Rect::Draw(unsigned int color, bool isFill)
{
	DrawBox(static_cast<int> (m_left), static_cast<int>(m_top), static_cast<int>(m_rigth), static_cast<int>(m_bottom), color, isFill);
}

void Rect::SetLT(float left, float top, float width, float bottom)
{
	m_left = left;
	m_top = top;
	m_rigth = width + left;
	m_bottom = top + bottom;
}

void Rect::SetCenter(float x, float y, float width, float height)
{
	m_left = x - width / 2;
	m_top = y - height / 2;
	m_rigth = width + x / 2;
	m_bottom = height + y / 2;
}

float Rect::GetWidth() const
{
	assert(m_rigth >= m_left);  //左右の座標入れ替わりチェック
	return m_rigth - m_left;
}

float Rect::GetHeight() const
{
	assert(m_bottom >= m_top);  //上下の座標入れ替わりチェック
	return m_bottom - m_top;
}

Vec2 Rect::GetCenter() const
{
	float x = (m_left + m_rigth) / 2;
	float y = (m_top + m_bottom) / 2;
	return Vec2{ x,y };
}

bool Rect::IsCollsion(const Rect& rect)
{
	//絶対に当たらないパターンをはじいていく
	if (m_left > rect.m_rigth) return false;
	if (m_top > rect.m_bottom) return false;
	if (m_rigth > rect.m_left) return false;
	if (m_bottom > rect.m_top) return false;
	//当たらないパターン以外は当たっている
	return true;
}
